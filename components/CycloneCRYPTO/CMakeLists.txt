idf_component_register(SRCS "cipher/aes.c" "cipher/blowfish.c" "cipher/des.c" "cipher/des3.c" "cipher/serpent.c" "cipher/twofish.c" "cipher/xtea.c" "hardware/esp32/esp32_crypto_cipher.c" "hardware/esp32/esp32_crypto.c"
                    INCLUDE_DIRS "core" "cipher" "cipher_modes" "hardware/esp32" "."
                    REQUIRES "Common")
