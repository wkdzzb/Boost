// Boost.Range library
//
//  Copyright Neil Groves 2009. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//
// For more information, see http://www.boost.org/libs/range/
//
#include <boost/range/adaptor/sliced.hpp>
#include <boost/range/algorithm/copy.hpp>
#include <boost/assign.hpp>
#include <algorithm>
#include <iostream>
#include <vector>

#include <boost/test/test_tools.hpp>
#include <boost/test/unit_test.hpp>

#include <boost/range/algorithm_ext/push_back.hpp>

namespace 
{
    void sliced_example_test()
    {
        using namespace boost::adaptors;
        using namespace boost::assign;

        std::vector<int> input;
        input += 1,2,3,4,5,6,7,8,9;
        
        boost::copy(
            input | sliced(2, 5),
            std::ostream_iterator<int>(std::cout, ","));


        std::vector<int> reference;
        reference += 3,4,5;

        std::vector<int> test;
        boost::push_back(test, input | sliced(2, 5));

        BOOST_CHECK_EQUAL_COLLECTIONS( reference.begin(), reference.end(),
            test.begin(), test.end() );
    }
}

boost::unit_test::test_suite*
init_unit_test_suite(int argc, char* argv[])
{
    boost::unit_test::test_suite* test
        = BOOST_TEST_SUITE( "RangeTestSuite.adaptor.sliced_example" );

    test->add( BOOST_TEST_CASE( &sliced_example_test ) );

    return test;
}
