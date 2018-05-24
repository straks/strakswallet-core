//
//  BRChainParams.h
//
//  Created by Aaron Voisine on 1/10/18.
//  Copyright (c) 2019 breadwallet LLC
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.

#ifndef BRChainParams_h
#define BRChainParams_h

#include "BRMerkleBlock.h"
#include "BRSet.h"
#include <assert.h>

typedef struct {
    uint32_t height;
    UInt256 hash;
    uint32_t timestamp;
    uint32_t target;
} BRCheckPoint;

typedef struct {
    const char * const *dnsSeeds; // NULL terminated array of dns seeds
    uint16_t standardPort;
    uint32_t magicNumber;
    uint64_t services;
    int (*verifyDifficulty)(const BRMerkleBlock *block, const BRSet *blockSet); // blockSet must have last 2016 blocks
    const BRCheckPoint *checkpoints;
    size_t checkpointsCount;
} BRChainParams;

static const char *BRMainNetDNSSeeds[] = {
    "sm001.alphaqub.com", "sm002.alphaqub.com", "sm003.alphaqub.com", "sm004.alphaqub.com", "sm005.alphaqub.com", NULL
};

static const char *BRTestNetDNSSeeds[] = {
    "st001.radixpi.com", "st002.radixpi.com", NULL
};

// blockchain checkpoints - these are also used as starting points for partial chain downloads, so they must be at
// difficulty transition boundaries in order to verify the block difficulty at the immediately following transition
static const BRCheckPoint BRMainNetCheckpoints[] = {
    {      0, uint256("00000df14d859c4b3219d93978bcf02afc123d2344a2ed39033e1208948aa7c0"), 1510790624, 0x1e0ffff0 },
    {      1, uint256("00000b6321951f2ed170bbc9b7a360995176f2df418b0e275149bfce2fde3d6c"), 1510792676, 0x1e0fffff },
    {      2, uint256("000001c4bb98a9d3863d26325d95d3ed774309a605c9b0b18746f14e50253a4c"), 1510792707, 0x1e0fffff },
    {      3, uint256("00000962952d27fb7f9d587a26b258673ed8c43f02152ffda9c1aefc48d2eb52"), 1510792827, 0x1e0fffff },
    {      4, uint256("000000073ea295b6b1d5e759a98df24f74a2bab00f35d6c5fa6aed2c989ad1ab"), 1510792831, 0x1e0fffff },
    {      5, uint256("000008c2110138f9598c74a2714b2729875d1a57dd0f6fe7953abee7ac15926f"), 1510792834, 0x1e0fffff },
    {      6, uint256("000000457c67eb82204f07141cdf1b1a0a7bf7d9f9853f32303a913ca84857c1"), 1510792839, 0x1e0fffff },
    {      7, uint256("000007cda7603c9ac8829b50bd5d5a828744ae0131eb3fe81b3cb94ab18355b2"), 1510792847, 0x1e0fffff },
    {      8, uint256("00000a5406e1aeb6173b34c60e14e0442709354ac46378db8792986933366291"), 1510792858, 0x1e0fffff },
    {      9, uint256("00000491760a7e6cf8fb72ef96626eae4b10242b2999c629336175252582e33a"), 1510792859, 0x1e0fffff },
    {     10, uint256("0000025f19e1714fd575bfe9e18e137625e731036da615f416d79f7edbdc1e81"), 1510792864, 0x1e0c4ccc },
    {     11, uint256("000004831046ed220f2f83e49b84dd791ab27dd64dab62585e26760da1bf9ab7"), 1510792886, 0x1e0bf1c6 },
    {     12, uint256("000002d7c1401b2dc3c14146734f003cf0ef0f4efdc573034633a06ee7f37eff"), 1510792893, 0x1e0b8e02 },
    {     13, uint256("000008bc6d705f2b7afa212a84daa7326949b96e6f68837923a86a75b62e80b8"), 1510792903, 0x1e0b20a8 },
    {     14, uint256("000002e47aa010b0da6e529c9612c46463e4d5e65b30c05c77218b3caab18f36"), 1510792907, 0x1e0aa8cb },
    {     15, uint256("000007f7d2ecdf53cdf6b83e74a80b77d6ff50d41fb258da0f7916ead6ac8f5a"), 1510792919, 0x1e0a256a },
    {     16, uint256("000005a9e2755809faf5f5d94834c2507c83607f65c7caa42e1376e6e3f7d4fb"), 1510792922, 0x1e099569 },
    {     17, uint256("000001a575ecfee1c1270c15f89ff4e0d61ae0a56d6060e4ad24dbb57755da2a"), 1510792925, 0x1e08f791 },
    {     18, uint256("00000604ef19971ccd8da4a7bb0b19b25e953bc5991752c1e83b25eb16f187e3"), 1510792926, 0x1e084a8f },
    {     19, uint256("000003f4d5dda04d2036c764f71bfa6e6e7662ace3b5924c29f526be40f451c0"), 1510792932, 0x1e07e7f1 },
    {     20, uint256("000001738cb5eba2e862b6f2f52cb0d8d3706aac5ec5ff739850cbd8c346e46d"), 1510792935, 0x1e078499 },
    {     21, uint256("00000487414e16de5ab744d84522856d4c65f07e6349526ee683a7f929a11e33"), 1510792938, 0x1e07214b },
    {     22, uint256("000004d667c0758875c4f8ef80d4e6a5b128baa5c51ed27e28551ec5921eac8e"), 1510792967, 0x1e06bef4 },
    {     23, uint256("000001a8a3ec6430d607bdc537873ea696e883e05b4501f26312ca6e7e7046e5"), 1510792969, 0x1e065eaf },
    {     24, uint256("000003b53973108148a91cedc3e0c8886f47eee29cbb66d10fa97e9101edeb0d"), 1510792976, 0x1e0601c9 },
    {     25, uint256("0000007155fbef73b5bc40da8954f9ab4b7859385b8c30b7986ea243c850ad46"), 1510792977, 0x1e05a9cd },
    {     26, uint256("000004934d4ef4c4b43a45b10c0291b142951c7c9d96aa7628ace469378b4298"), 1510792978, 0x1e055887 },
    {     27, uint256("00000007201452e5dca4a3543617749ae5217d73075dbb0ac1c8ef6fa3698d47"), 1510792991, 0x1e051012 },
    {     28, uint256("0000004263c243598938d876c3b87ba2adf84d0c694b03eef7f1c8ec9eda690a"), 1510792991, 0x1e04ca20 },
    {     29, uint256("00000177eb4c9810c16d7bf5556e30e94084addb2454a0a43becde654e37b5d7"), 1510792994, 0x1e048702 },
    {     30, uint256("000000a28f592b10ac9946234bd443a4a004b96071742126e05a91622831ec05"), 1510793020, 0x1e0446fb },
    {     31, uint256("0000012681f3780d1a82086da82e45149bf52e38b5d669e7b2ca1415da2dcd1e"), 1510793026, 0x1e040a41 },
    {  19760, uint256("000000000008cdaee7a7cc3e8e5336ce2426eb7079f9a43a4dbf15ac8c08cbec"), 1512084057, 0x1b5260f5 },
    {  34000, uint256("00000000008fa092d7379523824d65470e1f62afdd9e4efe225b2a80461c16a1"), 1512998850, 0x1c00bf46 },
    {  50400, uint256("00000000003c5729841f6d3f44d267e6be7e6b9a7cd4c9b2480a396f22e7561e"), 1514042029, 0x1b3d2d82 },
    {  94858, uint256("000000000003b195d823ee34f2ffa36933e4696fa845508e0fa9238e0dbb9718"), 1516904707, 0x1b0fe64b },
    { 136201, uint256("00000000000def1328cef45871f0cd91dabd28dc5ba117535cbcee19eebdf79c"), 1519582828, 0x1b3b14c7 },
    { 160285, uint256("00000000000147b96ecc7ab3248dcbabd87b2193bf045750fce80db89465b338"), 1521176462, 0x1b1f163f }
};

static const BRCheckPoint BRTestNetCheckpoints[] = {
    {       0, uint256("000000cd747bd0b653e1fe417b60c1d9e990600cf2ff193404ea12c3ecb348b4"), 1510791350, 0x1e0ffff0 },
    {  119692, uint256("000004d943ed36053076a62b20cc7bec6a8a4c66ed1f6a6e88deeca015ff555a"), 1512085024, 0x1e075798 },
    {  195182, uint256("0000001cbc01c2d26da194f44fd63e35eb87e65642c8611c93e9c14a2f2c0a0d"), 1512998970, 0x1e0fffff },
    {  232597, uint256("0000023d86e2181d63c6db4cb82e5889737b824efd71904f03fe76898a941211"), 1519544748, 0x1e0fffff }
};

static int BRMainNetVerifyDifficulty(const BRMerkleBlock *block, const BRSet *blockSet)
{
    const BRMerkleBlock *previous, *b = NULL;
    uint32_t i;
    
    assert(block != NULL);
    assert(blockSet != NULL);
    
    // check if we hit a difficulty transition, and find previous transition block
    //if ((block->height % BLOCK_DIFFICULTY_INTERVAL) == 0) {
    //    for (i = 0, b = block; b && i < BLOCK_DIFFICULTY_INTERVAL; i++) {
    //        b = BRSetGet(blockSet, &b->prevBlock);
    //    }
    //}
    
    //previous = BRSetGet(blockSet, &block->prevBlock);
    return BRMerkleBlockVerifyDifficulty(block, blockSet);
}

static int BRTestNetVerifyDifficulty(const BRMerkleBlock *block, const BRSet *blockSet)
{
    return 1; // XXX skip testnet difficulty check for now
}

static const BRChainParams BRMainNetParams = {
    BRMainNetDNSSeeds,
    7575,       // standardPort
    0x2cf0d5b0, // magicNumber
    0,          // services
    BRMainNetVerifyDifficulty,
    BRMainNetCheckpoints,
    sizeof(BRMainNetCheckpoints)/sizeof(*BRMainNetCheckpoints)
};

static const BRChainParams BRTestNetParams = {
    BRTestNetDNSSeeds,
    7565,      // standardPort
    0xd1d51e2a, // magicNumber
    0,          // services
    BRTestNetVerifyDifficulty,
    BRTestNetCheckpoints,
    sizeof(BRTestNetCheckpoints)/sizeof(*BRTestNetCheckpoints)
};

#endif // BRChainParams_h
