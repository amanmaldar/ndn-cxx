/**
 * Copyright (C) 2013 Regents of the University of California.
 * @author: Jeff Thompson <jefft0@remap.ucla.edu>
 * See COPYING for copyright and distribution information.
 */

#include "management/control-response.hpp"
#include "management/fib-management-options.hpp"

#include <boost/test/unit_test.hpp>
#include <boost/test/output_test_stream.hpp>

using namespace std;

namespace ndn {

BOOST_AUTO_TEST_SUITE(TestNfdControl)

const uint8_t TestControlResponse[] = {0x65, 0x17, 0x66, 0x02, 0x01, 0x94, 0x67, 0x11, 0x4e, 0x6f, 0x74, 0x68, 0x69, 0x6e, 0x67, 0x20, 0x6e, 0x6f, 0x74, 0x20, 0x66, 0x6f, 0x75, 0x6e, 0x64};

const uint8_t TestFibManagementOptions[] = {
  0x68, 0x1e, 0x03, 0x16, 0x04, 0x09, 0x6c, 0x6f, 0x63, 0x61, 0x6c, 0x68,
  0x6f, 0x73, 0x74, 0x04, 0x03, 0x72, 0x65, 0x67, 0x04, 0x04, 0x74, 0x65,
  0x73, 0x74, 0x69, 0x01, 0x00, 0x6a, 0x01, 0x00
};

// ControlResponse

BOOST_AUTO_TEST_CASE (ControlResponseEncode)
{
  ndn::ControlResponse controlResponse(404, "Nothing not found");
  const Block &wire = controlResponse.wireEncode();

  BOOST_REQUIRE_EQUAL_COLLECTIONS(TestControlResponse, TestControlResponse+sizeof(TestControlResponse),
                                  wire.begin(), wire.end());
}

BOOST_AUTO_TEST_CASE (ControlResponseDecode)
{
  ndn::ControlResponse controlResponse;
  
  BOOST_REQUIRE_NO_THROW(controlResponse.wireDecode(Block(TestControlResponse, sizeof(TestControlResponse))));

  BOOST_REQUIRE_EQUAL(controlResponse.getCode(), 404);
  BOOST_REQUIRE_EQUAL(controlResponse.getText(), "Nothing not found");
}

// FibManagementOptions

BOOST_AUTO_TEST_CASE (FibManagementOptionsEncoding)
{
  Name n ("/localhost/reg/test");
  FibManagementOptions opt;

  opt.setName (n);
  opt.setFaceId (0);
  opt.setCost (0);

  const ndn::Block& blk = opt.wireEncode ();

  BOOST_REQUIRE_EQUAL_COLLECTIONS (TestFibManagementOptions,
                                   TestFibManagementOptions + sizeof (TestFibManagementOptions),
                                   blk.begin (), blk.end ());
}

BOOST_AUTO_TEST_CASE (FibManagementOptionsDecoding)
{
  Block blk (TestFibManagementOptions, sizeof (TestFibManagementOptions));
  Name n ("/localhost/reg/test");
  FibManagementOptions opt;

  BOOST_REQUIRE_NO_THROW (opt.wireDecode (blk));
  
  BOOST_CHECK_EQUAL (opt.getName (), n);
  BOOST_CHECK_EQUAL (opt.getFaceId (), 0);
  BOOST_CHECK_EQUAL (opt.getCost (), 0);
}


BOOST_AUTO_TEST_SUITE_END()

} // namespace ndn