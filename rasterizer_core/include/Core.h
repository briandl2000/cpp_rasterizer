#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <unordered_map>

#include <cstdint>

#ifdef _WIN32
#include <windows.h>
#endif 

namespace Rasterizer {

    using u8 = uint8_t;
    using u16 = uint16_t;
    using u32 = uint32_t;
    using u64 = uint64_t;
    using i8 = int8_t;
    using i16 = int16_t;
    using i32 = int32_t;
    using i64 = int64_t;
    using f32 = float;
    using f64 = double;

    #if defined(_MSC_VER)
    #define STATIC_ASSERT(expr, msg) static_assert(expr, msg)
    #elif defined(__GNUC__) || defined(__clang__)
    #define STATIC_ASSERT(expr, msg) _Static_assert(expr, msg)
    #else
    #error "Compiler not supported for STATIC_ASSERT"
    #endif

    STATIC_ASSERT(sizeof(u8) == 1, "u8 is not 1 byte");
    STATIC_ASSERT(sizeof(u16) == 2, "u16 is not 2 bytes");
    STATIC_ASSERT(sizeof(u32) == 4, "u32 is not 4 bytes");
    STATIC_ASSERT(sizeof(u64) == 8, "u64 is not 8 bytes");
    STATIC_ASSERT(sizeof(i8) == 1, "i8 is not 1 byte");
    STATIC_ASSERT(sizeof(i16) == 2, "i16 is not 2 bytes");
    STATIC_ASSERT(sizeof(i32) == 4, "i32 is not 4 bytes");
    STATIC_ASSERT(sizeof(i64) == 8, "i64 is not 8 bytes");
    STATIC_ASSERT(sizeof(f32) == 4, "f32 is not 4 bytes");
    STATIC_ASSERT(sizeof(f64) == 8, "f64 is not 8 bytes");

    template<typename T>
    using SharedPtr = std::shared_ptr<T>;
    template<typename T>
    using UniquePtr = std::unique_ptr<T>;
    template<typename T>
    using WeakPtr = std::weak_ptr<T>;

    template<typename T, typename... Args>
    SharedPtr<T> MakeShared(Args&&... args) {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }
    template<typename T, typename... Args>
    UniquePtr<T> MakeUnique(Args&&... args) {
        return std::make_unique<T>(std::forward<Args>(args)...);
    }

}