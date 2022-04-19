load("@rules_proto//proto:defs.bzl", "proto_library")

proto_library(
        name = "customer_Addressbook_proto",
        srcs = ["customer.Addressbook.proto"],
        )

cc_proto_library(
        name = "customer_Addressbook_cc_proto",
        deps = [
                ":customer_Addressbook_proto",
                ],
        )

package(default_visibility = ["//visibility:public"])
