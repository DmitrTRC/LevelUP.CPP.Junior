//
// Created by Dmitry Morozov on 18/3/23.
//

#include "Menu_Item.hpp"

#include <utility>

std::string MenuItem::getName() const {
	return name_;
}

MenuItem::MenuItem(std::string name, const std::function<void(std::any &param)> &action)
	: name_(std::move(name)), action_(action) {}

void MenuItem::Execute(std::any param) {

	action_(param);
}

