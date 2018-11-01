/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2013-2018 Regents of the University of California.
 *
 * This file is part of ndn-cxx library (NDN C++ library with eXperimental eXtensions).
 *
 * ndn-cxx library is free software: you can redistribute it and/or modify it under the
 * terms of the GNU Lesser General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later version.
 *
 * ndn-cxx library is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
 * PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.
 *
 * You should have received copies of the GNU General Public License and GNU Lesser
 * General Public License along with ndn-cxx, e.g., in COPYING.md file.  If not, see
 * <http://www.gnu.org/licenses/>.
 *
 * See AUTHORS.md for complete list of ndn-cxx authors and contributors.
 */

#ifndef NDN_CXX_LP_TAGS_HPP
#define NDN_CXX_LP_TAGS_HPP

#include "cache-policy.hpp"
#include "empty-value.hpp"
#include "prefix-announcement-header.hpp"
#include "../tag.hpp"

namespace ndn {
namespace lp {

/** \class IncomingFaceIdTag
 *  \brief a packet tag for IncomingFaceId field
 *
 *  This tag can be attached to Interest, Data, Nack.
 */
typedef SimpleTag<uint64_t, 10> IncomingFaceIdTag;

/** \class NextHopFaceIdTag
 *  \brief a packet tag for NextHopFaceId field
 *
 *  This tag can be attached to Interest.
 */
typedef SimpleTag<uint64_t, 11> NextHopFaceIdTag;

/** \class CachePolicyTag
 *  \brief a packet tag for CachePolicy field
 *
 *  This tag can be attached to Data.
 */
typedef SimpleTag<CachePolicy, 12> CachePolicyTag;

/** \class CongestionMarkTag
 *  \brief a packet tag for CongestionMark field
 *
 *  This tag can be attached to Interest, Data, Nack.
 */
typedef SimpleTag<uint64_t, 13> CongestionMarkTag;

/** \class NonDiscoveryTag
 *  \brief a packet tag for NonDiscovery field
 *
 *  This tag can be attached to Interest.
 */
typedef SimpleTag<EmptyValue, 14> NonDiscoveryTag;

/** \class PrefixAnnouncementTag
 *  \brief a packet tag for PrefixAnnouncement field
 *
 *  This tag can be attached to Data.
 */
typedef SimpleTag<PrefixAnnouncementHeader, 15> PrefixAnnouncementTag;

typedef SimpleTag<uint16_t, 0x60000002> intHopsTag;
typedef SimpleTag<uint64_t, 0x60000003> intArrivalTimeTag;
typedef SimpleTag<uint32_t, 0x60000004> intProcessingTimeTag;
typedef SimpleTag<uint64_t, 0x60000005> dataProduceTimeTag;


} // namespace lp
} // namespace ndn

#endif // NDN_CXX_LP_TAGS_HPP
