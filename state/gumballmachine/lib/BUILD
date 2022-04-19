#cc_library(
#        name = "State",
#        srcs = ["State.cpp"],
#        hdrs = ["State.h"],
#        deps = [
#                ":GumballMachine",
#                ],
#        visibility = ["//main:__pkg__"],
#        )
#
#cc_library(
#        name = "GumballMachine",
#        srcs = ["GumballMachine.cpp"],
#        hdrs = ["GumballMachine.h"],
#        deps = [
#                ":State",
#                ],
#        visibility = ["//main:__pkg__"],
#        )

cc_library(
        name = "build-all-files",
        srcs = glob(["*.cpp"]),
        hdrs = glob(["*.h"]),
        visibility = ["//main:__pkg__"],
        )
