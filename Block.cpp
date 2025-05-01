#include "Block.h"
#include "sha256.h"
#include <sstream>

Block::Block(uint8_t nIndexIn, const string &sDataIn) : _nIndex(nIndexIn), _sData(sDataIn)
{
    _nNonce = -1;
    _tTime = time(nullptr);
}

string Block::GetHash()
{
    return _sHash;
}

void Block::MineBlock(uint8_t _nDifficulty)
{
    char cstr[_nDifficulty + 1];

    for (int i = 0; i < _nDifficulty; i++)
    {
        cstr[i] = '0';
    }

    cstr[_nDifficulty] = '\0';

    string str(cstr);

    do
    {
        _nNonce++;
        _sHash = _CalculateHash();
    } while (_sHash.substr(0, _nDifficulty) != str);

    cout << "Block mined: " << _sHash << endl;
}

inline string Block::_CalculateHash() const
{
    stringstream ss;
    ss << _nIndex << _tTime << _sData << _nNonce << sPrevHash;

    return sha256(ss.str());
}