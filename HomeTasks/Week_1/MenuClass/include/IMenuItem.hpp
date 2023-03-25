//
// Created by Dmitry Morozov on 18/3/23.
//

#ifndef LEVELUP_CPP_JUNIOR_HOMETASKS_WEEK_1_MENUCLASS_SRC_I_MENU_ITEM_HPP_
#define LEVELUP_CPP_JUNIOR_HOMETASKS_WEEK_1_MENUCLASS_SRC_I_MENU_ITEM_HPP_

#include <any>
#include <string>

class IMenuItem {
 public:
  virtual ~IMenuItem() = default;

  [[nodiscard]] virtual std::string getName() const = 0;
  virtual void Execute(std::any) = 0;

};

#endif //LEVELUP_CPP_JUNIOR_HOMETASKS_WEEK_1_MENUCLASS_SRC_I_MENU_ITEM_HPP_
