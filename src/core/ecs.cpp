#include "../../vapour/core/ecs.h"
#include <iostream>

using namespace vapour;
using namespace vapour::ecs;

Context::Context() {
	for (ID entity = 0; entity < vapour::config::entity_cap; entity++) {
		available_ids.push(entity);
	}

	component_flags = new std::vector<bool>[vapour::config::component_cap];
	component_registry = new ComponentRegister[vapour::config::component_cap];
}

Context& Context::instance() {
	static Context instance;
	return instance;
}

ID Context::spawn() {
	ID id = available_ids.front();
	available_ids.pop();

	return id;
}

ComponentID Context::get_component_id(const char* name) {
	return component_ids.at(name);
}

void Context::add_component_flag(ID id, ComponentID component) {
	component_flags[id][component] = true;
}

void Context::remove_component_flag(ID id, ComponentID component) {
	component_flags[id][component] = false;
}

void Context::clear_component_flags(ID id) {
	std::fill(component_flags[id].begin(), component_flags[id].end(), 0);
}

bool Context::has_component_flag(ID id, ComponentID component) {
	return component_flags[id][component];
}

void Context::delete_components(ID id) {
	std::vector<bool> components = component_flags[id];
	for (unsigned int i = 0; i < vapour::config::component_cap; i ++) {
		if (components[i]) {
			remove_component(id, i);
		}
	}

	clear_component_flags(id);
}

EntityWrapper::EntityWrapper(ID _id) {
	id = _id;
}

void EntityWrapper::destroy() {
	vapour::context.delete_components(id);
}

EntityWrapper EntityWrapper::spawn() {
	return EntityWrapper(vapour::context.spawn());
}