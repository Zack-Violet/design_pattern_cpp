#include <iostream>
#include <string>
#include <memory>
#include "../lib/include/Waitress.h"
#include "../lib/include/Menus.h"

int main()
{
    std::unique_ptr<MenuComponent> _pancake_house_menu(new Menu("PANCAKE HOUSE MENU", "Breakfast"));
    std::unique_ptr<MenuComponent> _diner_menu(new Menu("DINER MENU", "Lunch"));
    std::unique_ptr<MenuComponent> _dessert_menu(new Menu("DESSERT MENU", "Dessert of course!"));
    std::unique_ptr<MenuComponent> _cafe_menu(new Menu("CAFE MENU", "Dinner"));
    std::unique_ptr<MenuComponent> _coffee_menu(new Menu("COFFEE MENU", "Stuff to go with your afternoon coffee"));

    _pancake_house_menu->add(std::unique_ptr<MenuComponent>(new MenuItem("K&B's Pancake Breakfast", "Pancakes with scrambled eggs, and toast", true, 2.99)));
    _pancake_house_menu->add(std::unique_ptr<MenuComponent>(new MenuItem("Regular Pancake Breakfast", "Pancakes with fried eggs, sausage", false, 2.99)));
    _pancake_house_menu->add(std::unique_ptr<MenuComponent>(new MenuItem("Blueberry Pancakes", "Pancakes made with fresh blueberries, and blueberry syrup", true, 3.49)));
    _pancake_house_menu->add(std::unique_ptr<MenuComponent>(new MenuItem("Waffles", "Waffles, with your choice of blueberries or strawberries", true, 3.59)));

    _diner_menu->add(std::unique_ptr<MenuComponent>(new MenuItem("Vegetarian BLT", "(Fakin') Bacon with lettuce & tomato on whole wheat", true, 2.99)));
    _diner_menu->add(std::unique_ptr<MenuComponent>(new MenuItem("BLT", "Bacon with lettuce & tomato on whole wheat", false, 2.99)));
    _diner_menu->add(std::unique_ptr<MenuComponent>(new MenuItem("Soup of the day", "A bowl of the soup of the day, with a side of potato salad", false, 3.29)));
    _diner_menu->add(std::unique_ptr<MenuComponent>(new MenuItem("Hotdog", "A hot dog, with saurkraut, relish, onions, topped with cheese", false, 3.05)));
    _diner_menu->add(std::unique_ptr<MenuComponent>(new MenuItem("Steamed Veggies and Brown Rice", "Steamed vegetables over brown rice", true, 3.99)));
    _diner_menu->add(std::unique_ptr<MenuComponent>(new MenuItem("Pasta", "Spaghetti with Marinara Sauce, and a slice of sourdough bread", true, 3.89)));

    _dessert_menu->add(std::unique_ptr<MenuComponent>(new MenuItem("Apple Pie", "Apple pie with a flakey crust, topped with vanilla icecream", true, 1.59)));
    _dessert_menu->add(std::unique_ptr<MenuComponent>(new MenuItem("Cheesecake", "Creamy new York cheesecake, with a chocolate graham crust", true, 1.99)));
    _dessert_menu->add(std::unique_ptr<MenuComponent>(new MenuItem("Sorbet", "A scoop of raspberry and a scoop of lime", true, 1.89)));
    _diner_menu->add(std::move(_dessert_menu));

    _cafe_menu->add(std::unique_ptr<MenuComponent>(new MenuItem("Veggie Burger and Air Fries", "Veggie burger on a whole wheat bun, lettuce, tomato, and fries", true, 3.99)));
    _cafe_menu->add(std::unique_ptr<MenuComponent>(new MenuItem("Soup of the day", "A cup of the soup of the day, with a side salad", false, 3.69)));
    _cafe_menu->add(std::unique_ptr<MenuComponent>(new MenuItem("Burrito", "A large burrito, with whole pinto beans, salsa, guacamole", true, 4.29)));

    _coffee_menu->add(std::unique_ptr<MenuComponent>(new MenuItem("Coffee Cake", "Crumbly cake topped with cinnamon and walnuts", true, 1.59)));
    _coffee_menu->add(std::unique_ptr<MenuComponent>(new MenuItem("Bagel", "Flavors include sesame, poppyseed, cinnamon raisin, pumpkin", false, 0.69)));
    _coffee_menu->add(std::unique_ptr<MenuComponent>(new MenuItem("Biscotti", "Three almond or hazelnut biscotti cookies", true, 0.89)));

    _cafe_menu->add(std::move(_coffee_menu));

    std::unique_ptr<MenuComponent> _all_menus(new Menu("ALL MENUS", "All menus combined"));

    _all_menus->add(std::move(_pancake_house_menu));
    _all_menus->add(std::move(_diner_menu));
    _all_menus->add(std::move(_cafe_menu));

    std::unique_ptr<Waitress> _waitress(new Waitress(std::move(_all_menus)));
    _waitress->printMenu();

    return 0;
}
