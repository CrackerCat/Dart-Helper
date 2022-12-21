#pragma once
#include <cstdint>
#include <map>
#include <string>
#include "globals.h"

static const int32_t kMagicValue = 0xdcdcf5f5;
enum SnapshotKind {
	kFull,      // Full snapshot of an application.
	kFullCore,  // Full snapshot of core libraries. Agnostic to null safety.
	kFullJIT,   // Full + JIT code
	kFullAOT,   // Full + AOT code
	kNone,      // gen_snapshot
	kInvalid
};

class Deserializer;
struct SnapshotHeader
{
	std::int32_t MagicValue;
	std::int64_t Length;
	SnapshotKind Kind;
	//�汾Hash��
	std::string VersionHash;
	std::string Features;
};

struct SnapshotHeader;
class Snapshot
{
public:
	bool ParseSnapshot();
private:
	//����snapshotͷ��
	bool parseHeader(Deserializer& d);
	//��������
	bool parseRoots(Deserializer& d);
public:
	SnapshotHeader header;
	DartVersion dartVer;
};

