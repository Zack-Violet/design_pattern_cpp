cc_library(
        name = "PizzaIngredientFactory",
        srcs = ["PizzaIngredientFactory.cc"],
        hdrs = ["include/PizzaIngredientFactory.h"],
        copts = ["-Ilib/include"],
        visibility = ["//main:__pkg__"],
        )

cc_library(
        name = "Pizza",
        srcs = ["Pizza.cc"],
        hdrs = ["include/Pizza.h"],
        copts = ["-Ilib/include"],
        visibility = ["//main:__pkg__"],
        deps = [
                ":PizzaIngredientFactory",
                ],
        )

cc_library(
        name = "PizzaStore",
        srcs = ["PizzaStore.cc"],
        hdrs = ["include/PizzaStore.h"],
        copts = ["-Ilib/include"],
        visibility = ["//main:__pkg__"],
        deps = [
                ":PizzaIngredientFactory",
                ":Pizza",
                "//proto:customer_Addressbook_cc_proto",
                ],
        )
