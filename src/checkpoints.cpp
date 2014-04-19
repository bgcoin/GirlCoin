// Copyright (c) 2009-2012 The Bitcoin developers
// Copyright (c) 2011-2012 Litecoin Developers
// Copyright (c) 2014 Girlcoin Developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

#include "checkpoints.h"

#include "main.h"
#include "uint256.h"

namespace Checkpoints
{
    typedef std::map<int, uint256> MapCheckpoints;

    //
    // What makes a good checkpoint block?
    // + Is surrounded by blocks with reasonable timestamps
    //   (no blocks before with a timestamp after, none after with
    //    timestamp before)
    // + Contains no strange transactions
    //

    static MapCheckpoints mapCheckpoints =
            boost::assign::map_list_of
        ( 0, uint256("0x81b4b80c801e7158a0f547984cadbe4e52b11cd3fe27c1fc2870ea8818ac2b6a"))
		( 1, uint256("0x4617ec03316b4584cf584f1121908557babd9170b0b556a83ac6f2b72ff9e23c"))
		( 2, uint256("0x3708b17be3cd6d3e9f803412a8dfa773afe19ab61385692a6ce60f4129e690e8"))
		( 3, uint256("0xc924d68d1456c8fc0450a890bd642aa20297afd14ed719d443089c1dbaa17531"))
		( 4, uint256("0xc59d650a8335c2054ba73e31b7701b4af10571236210b4794dc47d6bd3ea4b60"))
		( 5, uint256("0x209e3eb3a785f56896db60a30425efe52ba46d9f37ef661b7e458bb68811ae08"))
		( 6, uint256("0xa5976cf88da92c311c642aac4e660c207e3bac7a1dc1e2185e1187bb98a58de4"))
		( 7, uint256("0x43d46a6b74f1419e240b384ef6fa1b7179e025eb840e322302cc693259071200"))
		( 8, uint256("0x63bbc5526b4577f43ade62215a4dffc1734def9b9ad973439a1d71c3086824e1"))
		( 9, uint256("0xf7e83e2acc98544e3fb5037c68658b156db086e0f415d345612dace8b6d2136e"))
		( 10, uint256("0xe0fe37faec70823739c482a0b655d149e3ca917acce3c690125d1743eca76aa8"))
		;


    bool CheckBlock(int nHeight, const uint256& hash)
    {
        if (fTestNet) return true; // Testnet has no checkpoints

        MapCheckpoints::const_iterator i = mapCheckpoints.find(nHeight);
        if (i == mapCheckpoints.end()) return true;
        return hash == i->second;
		// return true;
    }

    int GetTotalBlocksEstimate()
    {
        if (fTestNet) return 0;
	
        return mapCheckpoints.rbegin()->first;
		// return 0;
    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
        if (fTestNet) return NULL;

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, mapCheckpoints)
        {
            const uint256& hash = i.second;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
                return t->second;
				// return NULL;
        }
        return NULL;
    }
}
