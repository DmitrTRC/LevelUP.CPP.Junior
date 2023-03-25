//
// Created by Dmitry Morozov on 18/3/23.
//

#ifndef LEVELUP_CPP_JUNIOR_MAIN_HOMETASKS_WEEK_1_MENUCLASS_SRC_MENU_ITEM_HPP_
#define LEVELUP_CPP_JUNIOR_MAIN_HOMETASKS_WEEK_1_MENUCLASS_SRC_MENU_ITEM_HPP_

#include "IMenuItem.hpp"

#include <functional>
#include <string>
#include <any>

class MenuItem : public IMenuItem {
 public:
  MenuItem(std::string name, const std::function<void(std::any &param)> &action);
  ~MenuItem() override = default;

  [[nodiscard]] std::string getName() const override;
  void Execute(std::any param) override;

 private:
  std::string name_;
  std::variant<std::function<void(std::any &param)>, std::shared_ptr<IMenu>> action_;

};

#endif //LEVELUP_CPP_JUNIOR_MAIN_HOMETASKS_WEEK_1_MENUCLASS_SRC_MENU_ITEM_HPP_
