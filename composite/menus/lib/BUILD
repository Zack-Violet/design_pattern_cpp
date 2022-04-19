#cc_library(
#        name = "build-all-files",
#        srcs = glob(["*.cpp"]),
#        hdrs = glob(["*.h"]),
#        visibility = ["//main:__pkg__"],
#        )

cc_library(
        name = "Menus",
        srcs = ["Menus.cpp"],
        hdrs = ["include/Menus.h"],
        copts = ["-Ilib/include"],
        visibility = ["//main:__pkg__"],
        )

cc_library(
        name = "Waitress",
        srcs = ["Waitress.cpp"],
        hdrs = ["include/Waitress.h"],
        copts = ["-Ilib/include"],
        deps = [
                ":Menus",
                ],
        visibility = ["//main:__pkg__"],
        )
