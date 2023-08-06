#pragma once

#include <cstdint>
#include <cstdlib>
#include <unordered_map>
#include <queue>
#include <bitset>

#include "../../prefs.h"

namespace vapour {
	using ID          = uint32_t;

	namespace ecs {
		class Context;
	}

	static ecs::Context context;

	namespace ecs {
		using ComponentID = uint16_t;

		struct ComponentRegister {
			uint8_t* id_to_data[ENTITY_CAP];
			ID data_to_id[ENTITY_CAP];
			uint8_t* start;
			size_t index_index;
			size_t component_size;

			ComponentRegister() {
				index_index = 0;
			}

			void allocate(size_t size) {
				component_size = size;
				start = (uint8_t*)malloc(ENTITY_CAP * component_size);
			}
		};

		struct EntityWrapper;

		class Context {
		public:
			friend EntityWrapper;
			bool on = true;

			Context();

			ID spawn();

			template <typename T>
			void register_component() {
				component_ids.insert(std::make_pair(typeid(T).name(), current_component_id));
				component_registry[current_component_id++].allocate(sizeof(T));
			}

			template <typename T>
			ComponentRegister* handle() {
				return &component_registry[get_component_id(typeid(T).name())];
			}

		private:
			ComponentID get_component_id(const char* name);
			void        add_component_flag(ID id, ComponentID component);
			void        remove_component_flag(ID id, ComponentID component);
			void        clear_component_flags(ID id);
			bool        has_component_flag(ID id, ComponentID component);
			void        delete_components(ID id);

			template <typename T>
			T* add_component(ID id) {
				ComponentID component_id = get_component_id(typeid(T).name());
				ecs::ComponentRegister* r = &component_registry[component_id];

				uint8_t* index = r->start + (r->index_index * sizeof(T));
				new (index) T;

				r->id_to_data[id] = index;
				r->data_to_id[r->index_index] = id;

				r->index_index++;

				add_component_flag(id, component_id);

				return (T*)index;
			}

			void remove_component(ID id, ComponentID component) {
				ecs::ComponentRegister* r = &component_registry[component];

				remove_component_flag(id, component);

				r->index_index--;
				if (r->index_index == 0) return; // decrease size of component array

				ID end_data_id = r->data_to_id[r->index_index]; // id of data to be moved
				if (id == end_data_id) return; // if you're deleting the last element, then change the array size and move on

				uint8_t* deleted_data_index = r->id_to_data[id];
				uint8_t* end_data_index = r->id_to_data[end_data_id];

				// copy data from last slot of data into deleted slot

				memcpy(deleted_data_index, end_data_index, r->component_size);
				r->id_to_data[end_data_id] = deleted_data_index;
				r->data_to_id[(deleted_data_index - r->start) / r->component_size] = end_data_id;
			}

			template <typename T>
			T* get_component(ID id) {
				return (T*)(component_registry[get_component_id(typeid(T).name())].id_to_data[id]);
			}

			std::unordered_map<const char*, ComponentID> component_ids;
			ComponentID                                  current_component_id = 0;

			std::queue<ID> available_ids;

			std::bitset<COMPONENT_CAP> component_flags[COMPONENT_CAP];
			ecs::ComponentRegister     component_registry[COMPONENT_CAP];
		};

		template <typename T>
		struct ComponentRegisterHandle {
			struct Iterator {
				T* component;
				ID* id;

				Iterator(T* _component, ID* _id) {
					component = _component;
					id = _id;
				}

				bool operator!=(const Iterator& compare) const {
					return component != compare.component;
				}

				Iterator& operator++() {
					component++;
					id++;

					return *this;
				}

				const Iterator operator*() const { return *this; }
			};

			T* components;
			ID* ids;
			size_t* size;

			ComponentRegisterHandle() {
				ComponentRegister* _register = context.handle<T>();

				components = (T*)(_register->start);
				ids = _register->data_to_id;
				size = &_register->index_index;
			}

			ComponentRegisterHandle(ComponentRegister* _register) {
				components = (T*)(_register->start);
				ids = _register->data_to_id;
				size = &_register->index_index;
			}

			Iterator begin() const {
				return Iterator(components, ids);
			}

			Iterator end() const {
				return Iterator(&components[*size], &ids[*size]);
			}
		};

		struct EntityWrapper {
			ID id;

			EntityWrapper(ID _id);
			void destroy();

			template <typename T>
			T* add() {
				return ctx->add_component<T>(id);
			}

			template <typename T>
			void remove() {
				ctx->remove_component(id, ctx->get_component_id(typeid(T).name()));
			}

			template <typename T>
			T* get() {
				return ctx->get_component<T>(id);
			}

			template <typename T>
			bool has() {
				return ctx->has_component_flag(id, ctx->get_component_id(typeid(T).name()));
			}

			static EntityWrapper spawn();
		};
	}

	using entity  = ecs::EntityWrapper;

	/*
	class Context;

	namespace ECS {
		struct ComponentRegister {
			uint8_t* id_to_data[entity_CAP];
			ID data_to_id[entity_CAP];
			uint8_t* start;
			size_t index_index;

			ComponentRegister(size_t size) {
				start = (uint8_t*)malloc(size * entity_CAP);
				index_index = 0;
			}
		};

		template <typename T>
		struct ComponentRegisterHandle {
			struct Iterator {
				T* component;
				ID* id;
				entity entity;

				Iterator(T* _component, ID* _id, Context* ctx) {
					component = _component;
					id = _id;
				}

				bool operator!=(const Iterator& compare) const {
					return component != compare.component;
				}

				Iterator& operator++() {
					component++;
					entity++;
					Context* ctx = entity.par

					return *this;
				}

				const Iterator operator*() const { return *this; }
			};

			T* components;
			ID* entities;
			size_t* size;

			ComponentRegisterHandle(ComponentRegister* _register) {
				components = (T*)(_register->start);
				entities = _register->data_to_id;
				size = &_register->index_index;
			}

			Iterator begin() const {
				return Iterator(components, entities);
			}

			Iterator end() const {
				return Iterator(&components[*size], &entities[*size]);
			}
		};

		class ComponentManager {
		private:
			std::unordered_map<uintptr_t, ComponentRegister> registry;
		public:
			template <typename T>
			inline void Register() {
				registry.insert({
					(uintptr_t)(typeid(T).name()),
					ComponentRegister(sizeof(T))
					});
			}

			template <typename T>
			inline T* Add(ID id) {
				ComponentRegister* r = &registry.at((uintptr_t)(typeid(T).name()));

				uint8_t* index = r->start + (r->index_index * sizeof(T));
				new (index) T;

				r->id_to_data[id] = index;
				r->data_to_id[r->index_index] = id;

				r->index_index++;

				return (T*)index;
			}

			template <typename T>
			void Remove(ID id) {
				ComponentRegister* r = &registry.at((uintptr_t)(typeid(T).name()));

				r->index_index--;
				if (r->index_index == 0) return; // decrease size of component array

				ID end_data_id = r->data_to_id[r->index_index]; // id of data to be moved
				if (id == end_data_id) return; // if you're deleting the last element, then change the array size and move on

				uint8_t* deleted_data_index = r->id_to_data[id];
				uint8_t* end_data_index = r->id_to_data[end_data_id];

				// copy data from last slot of data into deleted slot

				memcpy(deleted_data_index, end_data_index, sizeof(T));
				r->id_to_data[end_data_id] = deleted_data_index;
				r->data_to_id[(deleted_data_index - r->start) / sizeof(T)] = end_data_id;
			}

			template <typename T>
			inline T* Get(ID id) {
				return (T*)(registry.at((uintptr_t)(typeid(T).name())).id_to_data[id]);
			}

			template <typename T>
			ComponentRegisterHandle<T> GetHandle() {
				return ComponentRegisterHandle<T>(&registry.at((uintptr_t)(typeid(T).name())));
			}
		};

		class System {};

		class SystemManager {
		public:
			template <typename T>
			inline T* Register() {
				T* system = new T();
				registry.insert({
					(uintptr_t)(typeid(T).name()),
					system
				});

				return system;
			}
		private:
			std::unordered_map<uintptr_t, System*> registry;
		};
	}

	class Context {
	public:
		ECS::ComponentManager component;
		ECS::SystemManager    system;

		Context() : component(), system() {
			for (ID entity = 0; entity < entity_CAP; entity++) {
				available_ids.push(entity);
			}
		}

		ID Instantiate() {
			ID id = available_ids.front();
			available_ids.pop();

			return id;
		}

		void Destroy(ID id) {
			available_ids.push(id);
		}
	private:
		std::queue<ID> available_ids;
	};

	class entity {
	public:
		ID id;
		Context* parent;

		entity(ID _id, Context* parent) {
			id = _id;
		}

		void Destroy() {
			parent->Destroy(id);
		}

		template <typename T>
		T* Add() {
			return parent->component.Add<T>();
		}

		template <typename T>
		void Remove() {
			parent->component.Remove<T>();
		}

		template <typename T>
		T* Get() {
			return parent->component.Get<T>();
		}
	private:
	};*/
}