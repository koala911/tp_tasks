
#pragma once

#include <gtest/gtest.h>
#include <string>

class WeatherTestCase : public ::testing::Test {
protected:
    void SetUp() override {
        moscow = "Moscow";
        dolgoprudny = "Dolgoprudny";
        responsec_city_JSON = "{\"list\":[{\"main\":{\"temp\":1488,\"name\":\"Moscow\",\"pressure\":7777}}]}";
        good_status_code = 200;
        expected_diff = 1260;
        expected_temp = 1488;
        API = "556689";
    }

    std::string moscow;
    std::string dolgoprudny;
    std::string responsec_city_JSON;
    std::string default_response_Moscow = "{\"list\":[{\"main\":{\"temp\":1488,\"name\":\"Moscow\",\"pressure\":7777}}]}";
    std::string default_response_Dolgoprudny = "{\"list\":[{\"main\":{\"temp\":228,\"name\":\"Dolgoprudny\",\"pressure\":7777}}]}";
    std::string API;
    int good_status_code;
    int expected_diff;
    float expected_temp;
};
