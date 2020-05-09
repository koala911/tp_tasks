//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#include "WeatherTestCase.h"
#include "WeatherMock.h"


using ::testing::AtLeast;
using ::testing::Return;


cpr::Response MyResponse(int code, const std::string& text) {
    cpr::Response response = cpr::Response();
    response.status_code = code;
    response.text = text;
    return response;
}


TEST_F(WeatherTestCase, testOne) {
    WeatherMock mock;
    ASSERT_NO_THROW(mock.SetApiKey(API));
}

TEST_F(WeatherTestCase, testTwo) {
    WeatherMock mock;
    EXPECT_CALL(mock, Get(moscow)).Times(AtLeast(1));
    ASSERT_THROW(mock.GetResponseForCity(moscow), std::invalid_argument);
}

TEST_F(WeatherTestCase, testThree) {
    WeatherMock mock;
    EXPECT_CALL(mock, Get(moscow)).Times(AtLeast(1)).WillRepeatedly(Return(MyResponse(good_status_code, default_response_Moscow)));
    EXPECT_EQ(mock.GetTemperature(moscow), expected_temp);
}

TEST_F(WeatherTestCase, testFour) {
    WeatherMock mock;
    EXPECT_CALL(mock, Get(moscow)).WillRepeatedly(Return(MyResponse(good_status_code, default_response_Moscow)));
    EXPECT_CALL(mock, Get(dolgoprudny)).WillRepeatedly(Return(MyResponse(good_status_code, default_response_Dolgoprudny)));
    EXPECT_EQ(mock.GetDifferenceString("Moscow", "Dolgoprudny"), "Weather in Moscow is warmer than in Dolgoprudny by 1260 degrees");
    EXPECT_EQ(mock.GetDifferenceString("Dolgoprudny", "Moscow"), "Weather in Dolgoprudny is colder than in Moscow by 1260 degrees");
}

TEST_F(WeatherTestCase, testFive) {
    WeatherMock mock;
    EXPECT_CALL(mock, Get(moscow)).WillOnce(Return(MyResponse(good_status_code, default_response_Moscow)));
    EXPECT_CALL(mock, Get(dolgoprudny)).WillOnce(Return(MyResponse(good_status_code, default_response_Dolgoprudny)));
    EXPECT_EQ(mock.FindDiffBetweenTwoCities(moscow, dolgoprudny), expected_diff);
}

TEST_F(WeatherTestCase, TestSix) {
    json expected = json::parse(responsec_city_JSON);
    WeatherMock mock;
    EXPECT_CALL(mock, Get(moscow)).Times(AtLeast(1)).WillOnce(Return(MyResponse(good_status_code, default_response_Moscow)));
    EXPECT_EQ(mock.GetResponseForCity(moscow), expected);
}
