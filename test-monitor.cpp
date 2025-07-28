#include <gtest/gtest.h>
#include "./monitor.h"

TEST(Monitor, NotOkWhenAnyVitalIsOffRange) {
  ASSERT_FALSE(vitalsOk(99, 102, 70)); // pulse high
  ASSERT_TRUE(vitalsOk(98.1, 70, 98)); // all normal
}

TEST(Monitor, CheckVitalsLogic) {
  // Temperature critical
  EXPECT_EQ(checkVitals(103, 80, 95), 2);
  EXPECT_EQ(checkVitals(94, 80, 95), 2);
  // Pulse out of range
  EXPECT_EQ(checkVitals(98, 59, 95), 3);
  EXPECT_EQ(checkVitals(98, 101, 95), 3);
  // SpO2 out of range
  EXPECT_EQ(checkVitals(98, 80, 89), 4);
  // All normal
  EXPECT_EQ(checkVitals(98, 80, 95), 1);
}

TEST(Monitor, VitalsOkCoversAllBranches) {
  // Temperature critical
  ASSERT_FALSE(vitalsOk(103, 80, 95));
  ASSERT_FALSE(vitalsOk(94, 80, 95));
  // Pulse out of range
  ASSERT_FALSE(vitalsOk(98, 59, 95));
  ASSERT_FALSE(vitalsOk(98, 101, 95));
  // SpO2 out of range
  ASSERT_FALSE(vitalsOk(98, 80, 89));
  // All normal
  ASSERT_TRUE(vitalsOk(98, 80, 95));
}
