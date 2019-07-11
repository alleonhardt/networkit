#ifndef NETWORKIT_BINARY_GRAPH_
#define NETWORKIT_BINARY_GRAPH_

namespace nkbg {
struct Header {
	char magic[8];
	uint64_t checksum;
	uint64_t features;
	uint64_t nodes;
	uint64_t chunks;
	uint64_t offsetBaseData;
	uint64_t offsetAdjLists;
	uint64_t offsetAdjTranspose;
	uint64_t offsetWeights;
};

enum WEIGHT_FORMAT {
	VARINT = 0,
	SIGNED_VARINT = 1,
	DOUBLE = 2,
	FLOAT = 3
};

static constexpr uint8_t DELETED_BIT = 0x1; // bit 0
static constexpr uint64_t DIR_MASK = 0x1; // bit 0
static constexpr uint64_t WGHT_MASK = 0x6; //bit 1-2
static constexpr uint64_t WGHT_SHIFT = 0x1;

}
#endif