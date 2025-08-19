#include <gtest/gtest.h>
#include "./monitor.h"

TEST(Monitor, TemperatureCheck) {
  EXPECT_EQ(isTemperatureOk(98.6f), 1);
  EXPECT_EQ(isTemperatureOk(102.1f), 0);  // temp high
  EXPECT_EQ(isTemperatureOk(94.9f), 0);  // temp low
}

TEST(Monitor, PulseRateCheck) {
  EXPECT_EQ(isPulseRateOk(70), 1);
  EXPECT_EQ(isPulseRateOk(59), 0);  // pulse low
  EXPECT_EQ(isPulseRateOk(101), 0);  // pulse high
}

TEST(Monitor, Spo2Check) {
  EXPECT_EQ(isSpo2Ok(95), 1);
  EXPECT_EQ(isSpo2Ok(89), 0);  // spo2 low
}

TEST(Monitor, VitalsOkIntegration) {
  // All normal
  ASSERT_TRUE(vitalsOk(98.1, 70, 98));
  // Each vital abnormal
  ASSERT_FALSE(vitalsOk(103, 70, 98));  // temp high
  ASSERT_FALSE(vitalsOk(98.1, 59, 98));  // pulse low
  ASSERT_FALSE(vitalsOk(98.1, 70, 89));  // spo2 low
}
