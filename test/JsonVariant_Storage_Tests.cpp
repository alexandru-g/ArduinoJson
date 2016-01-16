// Copyright Benoit Blanchon 2014-2015
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson

#include <stdint.h>
#include <limits>
#include <gtest/gtest.h>
#include <ArduinoJson.h>

class JsonVariant_Storage_Tests : public ::testing::Test {
 protected:
  template <typename T>
  void testValue(T expected) {
    JsonVariant variant = expected;
    EXPECT_EQ(expected, variant.as<T>());
  }

  template <typename T>
  void testReference(T &expected) {
    JsonVariant variant = expected;
    EXPECT_EQ(expected, variant.as<T &>());
  }

  template <typename T>
  void testNumericType() {
    T min = std::numeric_limits<T>::min();
    T max = std::numeric_limits<T>::max();

    JsonVariant variantMin = min;
    JsonVariant variantMax = max;

    EXPECT_EQ(min, variantMin.as<T>());
    EXPECT_EQ(max, variantMax.as<T>());
  }
};

TEST_F(JsonVariant_Storage_Tests, Null) { testValue<const char *>(NULL); }
TEST_F(JsonVariant_Storage_Tests, String) { testValue<const char *>("hello"); }

TEST_F(JsonVariant_Storage_Tests, False) { testValue<bool>(false); }
TEST_F(JsonVariant_Storage_Tests, True) { testValue<bool>(true); }

TEST_F(JsonVariant_Storage_Tests, Double) { testNumericType<double>(); }
TEST_F(JsonVariant_Storage_Tests, Float) { testNumericType<float>(); }
TEST_F(JsonVariant_Storage_Tests, SChar) { testNumericType<signed char>(); }
TEST_F(JsonVariant_Storage_Tests, SInt) { testNumericType<signed int>(); }
TEST_F(JsonVariant_Storage_Tests, SLong) { testNumericType<signed long>(); }
TEST_F(JsonVariant_Storage_Tests, SShort) { testNumericType<signed short>(); }
TEST_F(JsonVariant_Storage_Tests, UChar) { testNumericType<unsigned char>(); }
TEST_F(JsonVariant_Storage_Tests, UInt) { testNumericType<unsigned int>(); }
TEST_F(JsonVariant_Storage_Tests, ULong) { testNumericType<unsigned long>(); }
TEST_F(JsonVariant_Storage_Tests, UShort) { testNumericType<unsigned short>(); }

TEST_F(JsonVariant_Storage_Tests, Int8) { testNumericType<int8_t>(); }
TEST_F(JsonVariant_Storage_Tests, Int16) { testNumericType<int16_t>(); }
TEST_F(JsonVariant_Storage_Tests, Int32) { testNumericType<int32_t>(); }
TEST_F(JsonVariant_Storage_Tests, Uint8) { testNumericType<uint8_t>(); }
TEST_F(JsonVariant_Storage_Tests, Uint16) { testNumericType<uint16_t>(); }
TEST_F(JsonVariant_Storage_Tests, Uint32) { testNumericType<uint32_t>(); }

TEST_F(JsonVariant_Storage_Tests, CanStoreObject) {
  DynamicJsonBuffer jsonBuffer;
  JsonObject &object = jsonBuffer.createObject();

  testReference(object);
}
