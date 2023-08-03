#include "ecs.h"
#include <iostream>

using namespace vapour;
using namespace vapour::core::ecs;

Context::Context() {
	for (ID entity = 0; entity < ENTITY_CAP; entity++) {
		available_ids.push(entity);
	}
}

EntityWrapper Context::spawn() {
	ID id = available_ids.front();
	available_ids.pop();

	return entity(id);
}

EntityWrapper Context::entity(ID id) {
	return EntityWrapper(id, this);
}

ComponentID Context::get_component_id(const char* name) {
	return component_ids.at(name);
}

void Context::add_component_flag(ID id, ComponentID component) {
	component_flags[id].set(component);
}

void Context::remove_component_flag(ID id, ComponentID component) {
	component_flags[id].reset(component);
}

void Context::clear_component_flags(ID id) {
	component_flags[id].reset();
}

bool Context::has_component_flag(ID id, ComponentID component) {
	return component_flags[id].test(component);
}

void Context::delete_components(ID id) {
	std::bitset<COMPONENT_CAP> components = component_flags[id];
	for (unsigned int i = 0; i < COMPONENT_CAP; i ++) {
		if (components[i]) {
			remove_component(id, i);
		}
	}

	clear_component_flags(id);
}

EntityWrapper::EntityWrapper(ID _id, Context* _ctx) {
	id = _id;
	ctx = _ctx;
}

void EntityWrapper::destroy() {
	ctx->delete_components(id);
}