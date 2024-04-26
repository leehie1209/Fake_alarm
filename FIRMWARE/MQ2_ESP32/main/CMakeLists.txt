idf_component_register(SRCS "MQ2_ESP32.c"
                            "MQ2/MQ2.c"
                    INCLUDE_DIRS ".")

target_compile_options(${COMPONENT_LIB} PRIVATE "-Wno-format")