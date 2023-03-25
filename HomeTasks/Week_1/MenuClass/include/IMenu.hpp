//
// Created by Dmitry Morozov on 19/3/23.
//

#ifndef LEVELIP_CPP_JUNIOR_MAIN_HOMETASKS_WEEK_1_MENUCLASS_INCLUDE_IMENU_HPP_
#define LEVELIP_CPP_JUNIOR_MAIN_HOMETASKS_WEEK_1_MENUCLASS_INCLUDE_IMENU_HPP_

#include <any>

class IMenu {
 public:
  virtual ~IMenu() = default;

  virtual void menu(std::any &param) = 0;
  virtual bool erase(size_t) = 0;
  virtual bool append(const IMenuItem &) = 0;
  virtual bool insert(size_t, const ImenuItem &) = 0;
};

#endif //LEVELIP_CPP_JUNIOR_MAIN_HOMETASKS_WEEK_1_MENUCLASS_INCLUDE_IMENU_HPP_
