idf_component_register(
    SRCS "wifi.c"  # Include your source files
    INCLUDE_DIRS "."
    PRIV_REQUIRES nvs_flash)
