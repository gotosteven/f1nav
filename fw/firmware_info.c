*/

#include <stdint.h>
#include <pios_board_info.h>
/**
 * We have 100 bytes for the whole description.
 *
 * Structure is:
 *   4 bytes: header: "OpFw".
 *   4 bytes: GIT commit tag (short version of SHA1).
 *   4 bytes: Unix timestamp of compile time.
 *   2 bytes: target platform. Should follow same rule as BOARD_TYPE and BOARD_REVISION in board define files.
 *  26 bytes: commit tag if it is there, otherwise branch name. '-dirty' may be added if needed. Zero-padded.
 *  20 bytes: SHA1 sum of the firmware.
 *  20 bytes: SHA1 sum of the uavo definitions.
 *  20 bytes: free for now.
 *
 */

#if (defined(__MACH__) && defined(__APPLE__))
const struct fw_version_info fw_version_blob __attribute__((used)) __attribute__((__section__("__TEXT,.fw_version_blob"))) = {
#else
const struct fw_version_info fw_version_blob __attribute__((used)) __attribute__((__section__(".fw_version_blob"))) = {
#endif
    .magic              = { 'O','p','F','w' },
    .commit_hash_prefix = 0x${HASH8},
    .timestamp          = ${UNIXTIME},
    .board_type         = ${BOARD_TYPE},
    .board_revision     = ${BOARD_REVISION},
    .commit_tag_name    = "${FWTAG}",
    .sha1sum            = { ${IMAGE_HASH_ARRAY} },
    .uavosha1           = { ${UAVO_HASH_ARRAY} },
};
