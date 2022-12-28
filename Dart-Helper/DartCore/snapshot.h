#pragma once
#include <cstdint>
#include <map>
#include <string>
#include "globals.h"
#include "dart_ver.h"

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
	//��ʼ�����õ�object��
	void AddBaseObjects(Deserializer* d);
private:
	//����snapshotͷ��
	bool parseHeader(Deserializer& d);
	//��ʼ������
	void initConfig();
	//��������
	bool parseRoots(Deserializer& d);
	bool parseRoots_2_1_2(Deserializer& d);
	bool parseRoots_3_0_0(Deserializer& d);

	void AddBaseObjects_2_1_2(Deserializer* d);
public:
	SnapshotHeader header;
	DartVersion dartVer;
	std::string arch;
};

