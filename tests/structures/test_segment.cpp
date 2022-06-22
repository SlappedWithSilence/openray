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

TEST(vec3Test, EqualitySelf) {
    vec3 v0 = vec3();
    vec3 v1 = vec3(1,1,1);

    EXPECT_EQ(v0 == v0, true);
    EXPECT_EQ(v1 == v1, true);
}

TEST(vec3Test, EqualityOther) {
    vec3 v0, v0_other = vec3();
    vec3 v1 = vec3(1,1,1);
    vec3 v1_other = vec3(1,1,1);

    EXPECT_EQ(v1 == v1_other, true);
    EXPECT_EQ(v0 == v1, false);
    EXPECT_EQ(v0, v0_other);
}

TEST(vec3Test, AddTwoVec3s) {
    vec3 v0 = vec3();
    vec3 v1 = {1, 1, 1};
    vec3 v2 = {2, 9, -1};
    vec3 v_sum = v0 + v1;

    EXPECT_EQ(v_sum.x == 1 && v_sum.y == 1 && v_sum.z == 1, true);
    v_sum = v1 + v2;
    EXPECT_EQ(v_sum.x == (v1.x + v2.x) && v_sum.y == (v1.y + v2.y) && v_sum.z == (v1.z + v2.z), true);
}

TEST(vec3Test, SubtractTwoVec3s) {
    vec3 v0 = vec3();
    vec3 v1 = vec3(1,1,1);
    vec3 v2 = vec3(2, 6, -4);

    vec3 v_diff = v0 - v1;
    EXPECT_EQ(v_diff, vec3(-1,-1,-1));
    EXPECT_EQ(v0-v2, vec3(-2, -6, 4));
}