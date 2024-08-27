# Install script for directory: /Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "TRUE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/Users/lucas/.espressif/tools/xtensa-esp32-elf/esp-12.2.0_20230208/xtensa-esp32-elf/bin/xtensa-esp32-elf-objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/mbedtls" TYPE FILE PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ FILES
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/aes.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/aria.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/asn1.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/asn1write.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/base64.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/bignum.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/build_info.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/camellia.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ccm.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/chacha20.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/chachapoly.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/check_config.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/cipher.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/cmac.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/compat-2.x.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/config_psa.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/constant_time.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ctr_drbg.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/debug.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/des.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/dhm.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ecdh.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ecdsa.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ecjpake.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ecp.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/entropy.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/error.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/gcm.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/hkdf.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/hmac_drbg.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/legacy_or_psa.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/lms.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/mbedtls_config.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/md.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/md5.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/memory_buffer_alloc.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/net_sockets.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/nist_kw.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/oid.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/pem.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/pk.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/pkcs12.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/pkcs5.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/pkcs7.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/platform.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/platform_time.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/platform_util.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/poly1305.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/private_access.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/psa_util.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ripemd160.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/rsa.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/sha1.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/sha256.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/sha512.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ssl.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ssl_cache.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ssl_ciphersuites.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ssl_cookie.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ssl_ticket.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/threading.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/timing.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/version.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/x509.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/x509_crl.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/x509_crt.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/mbedtls/x509_csr.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/psa" TYPE FILE PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ FILES
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/psa/crypto.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_builtin_composites.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_builtin_primitives.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_compat.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_config.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_driver_common.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_driver_contexts_composites.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_driver_contexts_primitives.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_extra.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_platform.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_se_driver.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_sizes.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_struct.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_types.h"
    "/Users/lucas/esp/v5.1-rc2/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_values.h"
    )
endif()

