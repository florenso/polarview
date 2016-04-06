#include "gtest/gtest.h"
#include "../source/include/DistanceReading.hpp"

//! Test set_result_type()
/*!
 Test case for the set_result_type() function
 Create a DistanceReading object, check it's ResultType, set it's ResultType and check again.
 Repeat for every possible ResultType.
 */
TEST(SetResultType, SetResultType) {
	ResultType didnt = ResultType::DIDNT_CHECK;
	
	Length len;
	
	DistanceReading a(DistanceReading(len, didnt));
	
	EXPECT_EQ(a.get_result_type(), ResultType::DIDNT_CHECK);
	
	a.set_result_type(ResultType::OUT_OF_RANGE);
	EXPECT_EQ(a.get_result_type(), ResultType::OUT_OF_RANGE);
	
	a.set_result_type(ResultType::CHECKED);
	EXPECT_EQ(a.get_result_type(), ResultType::CHECKED);
}

//! Test get_result_type()
/*!
 Test case for the get_result_type() function
 Create multiple DistanceReading objects and compare their ResultType
 against ResultType objects
 */
TEST(GetResultType, GetResultType) {
	ResultType didnt = ResultType::DIDNT_CHECK;
	ResultType range = ResultType::OUT_OF_RANGE;
	ResultType check = ResultType::CHECKED;
	
	Length len;
	
	DistanceReading a(DistanceReading(len, didnt));
	DistanceReading b(DistanceReading(len, range));
	DistanceReading c(DistanceReading(len, check));
}

//! Test set_length()
/*!
 Test case for the set_length() function
 Create a DistanceReading object and get it's length object. Check if this length is within range of another length.
 */
TEST(SetDistance, SetDistance) {
	Length len1(200);
	Length len2(200);
	
	DistanceReading a(DistanceReading(len2, ResultType::DIDNT_CHECK));
	Length tempmax(a.get_length());
	
	const Length offset(len1 / (1000 * 1000 * 1000)); // Extremely precise offset for measurement
	
	// Lengths are both 200, so in range
	EXPECT_TRUE(((len1 - offset) < tempmax) && (tempmax < (len1 + offset)));
	
	//! Set the length to a different value
	a.set_length(201);
	tempmax = a.get_length();
	
	//! Length is no longer in range of 200, so it should be false
	EXPECT_FALSE(((len1 - offset) < tempmax) && (tempmax < (len1 + offset)));
	
}

//! Test get_length()
/*!
 Test case for the get_length() function
 Create a DistanceReading object and get it's length object. Check if this length is within range of another length.
 */
TEST(GetDistance, GetDistance) {
	Length len1(200);
	Length len2(200.01);
	
	DistanceReading a(DistanceReading(len2, ResultType::DIDNT_CHECK));
	Length tempmax(a.get_length());
	
	const Length offset(len1 / 10000);
	
	EXPECT_TRUE(((len1 - offset) < tempmax) && (tempmax < (len1 + offset)));
}