//
// Created by Aaron on 6/21/2022.
//
#include "gtest/gtest.h"
#include "structures/segment.h"

using namespace openray;

TEST(vec3Test, Initialize) {
    openray::vec3 v = openray::vec3();
    EXPECT_EQ(v.x==v.y==v.z==0, true); // Default constructor initializes values to zero
    v = vec3(1,2,3);
    EXPECT_EQ(v.x==1 && v.y==2 && v.z==3, true); // Values constructor initializes to arguments
    v = {-1, -3, 2};
    EXPECT_EQ(v.x == -1 && v.y == -3 && v.z == 2, true); // Did the brace initializer work?
}

TEST(vec3Test, AddTwoVec3s) {
    vec3 v0 = vec3();
    vec3 v1 = {1, 1, 1};
    vec3 v2 = {2, 9, -1};
    vec3 v_sum = v0 + v1;

    EXPECT_EQ(v_sum.x == 1 && v_sum.y == 1 && v_sum.z == 1, true);
    v_sum = v1 + v2;
    EXPECT_EQ(v_sum.x == (v1.x + v2.x) && v_sum.y == (v1.y + v2.y) && v_sum.x == (v1.z + v2.z), true);
}