cmake_minimum_required(VERSION 3.5)

project(hyprsync-backend LANGUAGES C)

find_package(PkgConfig REQUIRED)
find_package(SQLite3 REQUIRED)
find_package(cJSON REQUIRED)
find_package(OpenSSL REQUIRED)

add_library(mongoose STATIC external/mongoose/mongoose.c)

add_executable(hyprsync-backend
    main.c
    handler/handler.h
    handler/handler.c
    handler/user_handler.h
    handler/user_handler.c
    handler/defaults.c
    handler/defaults.h

    external/mongoose/mongoose.c
    external/mongoose/mongoose.h

    model/user.h
    model/user.c
    model/crypt.h
    model/crypt.c

    service/database.c
    service/database.h
    service/user_service.c
    service/user_service.h

    util/util.h
    util/util.c
)

target_link_libraries(hyprsync-backend ${SQLite3_LIBRARIES} ${CJSON_LIBRARIES} ${OPENSSL_SSL_LIBRARY} ${OPENSSL_CRYPTO_LIBRARY})
target_include_directories(hyprsync-backend PRIVATE external/mongoose)

install(TARGETS hyprsync-backend RUNTIME DESTINATION bin)
