#ifndef TESTCHAIN_BLOCK_H
#define TESTCHAIN_BLOCK_H

#include <cstdint>
#include <iostream>

using namespace std;

class Block
{
public:
    string sPrevHash;

    Block(uint8_t nIndexIn, const string &sDataIn);

    string GetHash();

    void MineBlock(uint8_t _nDifficulty);

private:
    uint32_t _nIndex;
    int64_t _nNonce;
    string _sData;
    string _sHash;
    time_t _tTime;

    string _CalculateHash() const;
};

#endif