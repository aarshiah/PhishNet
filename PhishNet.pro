######################################################################
# Automatically generated by qmake (3.1) Tue Nov 5 10:35:39 2024
######################################################################

TEMPLATE = app
TARGET = PhishNet
INCLUDEPATH += .

# You can make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# Please consult the documentation of the deprecated API in order to know
# how to port your code away from it.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += build/clamav-config.h \
           build/clamav-types.h \
           build/clamav-version.h \
           build/clamav_rust.h \
           build/platform.h \
           build/target.h \
           clamav-milter/allow_list.h \
           clamav-milter/clamfi.h \
           clamav-milter/connpool.h \
           clamav-milter/netcode.h \
           clamd/clamd_others.h \
           clamd/localserver.h \
           clamd/scanner.h \
           clamd/server.h \
           clamd/session.h \
           clamd/shared.h \
           clamd/tcpserver.h \
           clamd/thrmgr.h \
           clamdscan/client.h \
           clamdscan/proto.h \
           clamonacc/clamonacc.h \
           clamscan/global.h \
           clamscan/manager.h \
           common/actions.h \
           common/cert_util.h \
           common/cert_util_internal.h \
           common/clamdcom.h \
           common/exeScanner.h \
           common/fdpassing.h \
           common/getopt.h \
           common/hostid.h \
           common/idmef_logging.h \
           common/misc.h \
           common/optparser.h \
           common/output.h \
           common/scanmem.h \
           common/service.h \
           common/tar.h \
           freshclam/execute.h \
           freshclam/notify.h \
           libclamav/7z_iface.h \
           libclamav/adc.h \
           libclamav/apm.h \
           libclamav/arc4.h \
           libclamav/asn1.h \
           libclamav/aspack.h \
           libclamav/autoit.h \
           libclamav/bcfeatures.h \
           libclamav/binhex.h \
           libclamav/blob.h \
           libclamav/builtin_bytecodes.h \
           libclamav/bytecode.h \
           libclamav/bytecode_api.h \
           libclamav/bytecode_api_impl.h \
           libclamav/bytecode_detect.h \
           libclamav/bytecode_hooks.h \
           libclamav/bytecode_priv.h \
           libclamav/cache.h \
           libclamav/clamav.h \
           libclamav/clambc.h \
           libclamav/conv.h \
           libclamav/cpio.h \
           libclamav/crtmgr.h \
           libclamav/cvd.h \
           libclamav/dconf.h \
           libclamav/default.h \
           libclamav/disasm-common.h \
           libclamav/disasm.h \
           libclamav/disasmpriv.h \
           libclamav/dlp.h \
           libclamav/dmg.h \
           libclamav/dsig.h \
           libclamav/egg.h \
           libclamav/elf.h \
           libclamav/encoding_aliases.h \
           libclamav/entconv.h \
           libclamav/entitylist.h \
           libclamav/events.h \
           libclamav/execs.h \
           libclamav/explode.h \
           libclamav/filetypes.h \
           libclamav/filetypes_int.h \
           libclamav/filtering.h \
           libclamav/fmap.h \
           libclamav/fpu.h \
           libclamav/fsg.h \
           libclamav/gif.h \
           libclamav/gpt.h \
           libclamav/hashtab.h \
           libclamav/hfsplus.h \
           libclamav/hostid_internal.h \
           libclamav/htmlnorm.h \
           libclamav/hwp.h \
           libclamav/iana_cctld.h \
           libclamav/iana_tld.h \
           libclamav/inffixed64.h \
           libclamav/inflate64.h \
           libclamav/inflate64_priv.h \
           libclamav/iowrap.h \
           libclamav/is_tar.h \
           libclamav/ishield.h \
           libclamav/iso9660.h \
           libclamav/jpeg.h \
           libclamav/json_api.h \
           libclamav/libmspack.h \
           libclamav/line.h \
           libclamav/lzma_iface.h \
           libclamav/macho.h \
           libclamav/matcher-ac.h \
           libclamav/matcher-bm.h \
           libclamav/matcher-byte-comp.h \
           libclamav/matcher-hash-types.h \
           libclamav/matcher-hash.h \
           libclamav/matcher-pcre.h \
           libclamav/matcher.h \
           libclamav/mbox.h \
           libclamav/mbr.h \
           libclamav/message.h \
           libclamav/mew.h \
           libclamav/mpool.h \
           libclamav/msdoc.h \
           libclamav/msexpand.h \
           libclamav/msxml.h \
           libclamav/msxml_parser.h \
           libclamav/ole2_encryption.h \
           libclamav/ole2_extract.h \
           libclamav/ooxml.h \
           libclamav/openioc.h \
           libclamav/others.h \
           libclamav/packlibs.h \
           libclamav/partition_intersection.h \
           libclamav/pdf.h \
           libclamav/pdfdecode.h \
           libclamav/pe.h \
           libclamav/pe_icons.h \
           libclamav/pe_structs.h \
           libclamav/perflogging.h \
           libclamav/petite.h \
           libclamav/phish_allow_list.h \
           libclamav/phish_domaincheck_db.h \
           libclamav/phishcheck.h \
           libclamav/png.h \
           libclamav/queue.h \
           libclamav/readdb.h \
           libclamav/rebuildpe.h \
           libclamav/regex_list.h \
           libclamav/regex_pcre.h \
           libclamav/regex_suffix.h \
           libclamav/rijndael.h \
           libclamav/rtf.h \
           libclamav/scanners.h \
           libclamav/sf_base64decode.h \
           libclamav/sis.h \
           libclamav/special.h \
           libclamav/spin.h \
           libclamav/stats.h \
           libclamav/stats_json.h \
           libclamav/str.h \
           libclamav/swf.h \
           libclamav/table.h \
           libclamav/text.h \
           libclamav/textdet.h \
           libclamav/textnorm.h \
           libclamav/tiff.h \
           libclamav/tnef.h \
           libclamav/type_desc.h \
           libclamav/udf.h \
           libclamav/unarj.h \
           libclamav/uniq.h \
           libclamav/unsp.h \
           libclamav/untar.h \
           libclamav/unzip.h \
           libclamav/upack.h \
           libclamav/upx.h \
           libclamav/uuencode.h \
           libclamav/vba_extract.h \
           libclamav/wwunpack.h \
           libclamav/www.h \
           libclamav/xar.h \
           libclamav/xdp.h \
           libclamav/xlm_extract.h \
           libclamav/xz_iface.h \
           libclamav/yara_arena.h \
           libclamav/yara_clam.h \
           libclamav/yara_compiler.h \
           libclamav/yara_exec.h \
           libclamav/yara_grammar.h \
           libclamav/yara_hash.h \
           libclamav/yara_lexer.h \
           libclamav/yara_parser.h \
           libclamav/yc.h \
           libclamunrar/archive.hpp \
           libclamunrar/array.hpp \
           libclamunrar/blake2s.hpp \
           libclamunrar/cmddata.hpp \
           libclamunrar/coder.hpp \
           libclamunrar/compress.hpp \
           libclamunrar/consio.hpp \
           libclamunrar/crc.hpp \
           libclamunrar/crypt.hpp \
           libclamunrar/dll.hpp \
           libclamunrar/encname.hpp \
           libclamunrar/errhnd.hpp \
           libclamunrar/extinfo.hpp \
           libclamunrar/extract.hpp \
           libclamunrar/filcreat.hpp \
           libclamunrar/file.hpp \
           libclamunrar/filefn.hpp \
           libclamunrar/filestr.hpp \
           libclamunrar/find.hpp \
           libclamunrar/getbits.hpp \
           libclamunrar/global.hpp \
           libclamunrar/hash.hpp \
           libclamunrar/headers.hpp \
           libclamunrar/headers5.hpp \
           libclamunrar/isnt.hpp \
           libclamunrar/list.hpp \
           libclamunrar/loclang.hpp \
           libclamunrar/log.hpp \
           libclamunrar/match.hpp \
           libclamunrar/model.hpp \
           libclamunrar/options.hpp \
           libclamunrar/os.hpp \
           libclamunrar/pathfn.hpp \
           libclamunrar/qopen.hpp \
           libclamunrar/rar.hpp \
           libclamunrar/rardefs.hpp \
           libclamunrar/rarlang.hpp \
           libclamunrar/raros.hpp \
           libclamunrar/rartypes.hpp \
           libclamunrar/rarvm.hpp \
           libclamunrar/rawint.hpp \
           libclamunrar/rawread.hpp \
           libclamunrar/rdwrfn.hpp \
           libclamunrar/recvol.hpp \
           libclamunrar/resource.hpp \
           libclamunrar/rijndael.hpp \
           libclamunrar/rs.hpp \
           libclamunrar/rs16.hpp \
           libclamunrar/savepos.hpp \
           libclamunrar/scantree.hpp \
           libclamunrar/secpassword.hpp \
           libclamunrar/sha1.hpp \
           libclamunrar/sha256.hpp \
           libclamunrar/smallfn.hpp \
           libclamunrar/strfn.hpp \
           libclamunrar/strlist.hpp \
           libclamunrar/suballoc.hpp \
           libclamunrar/system.hpp \
           libclamunrar/threadpool.hpp \
           libclamunrar/timefn.hpp \
           libclamunrar/ui.hpp \
           libclamunrar/unicode.hpp \
           libclamunrar/unpack.hpp \
           libclamunrar/version.hpp \
           libclamunrar/volume.hpp \
           libclamunrar_iface/unrar_iface.h \
           libfreshclam/dns.h \
           libfreshclam/libfreshclam.h \
           libfreshclam/libfreshclam_internal.h \
           sigtool/vba.h \
           unit_tests/checks.h \
           build/libclamav/version.h \
           build/libclammspack/config.h \
           clamonacc/c-thread-pool/thpool.h \
           clamonacc/client/client.h \
           clamonacc/client/communication.h \
           clamonacc/client/protocol.h \
           clamonacc/client/socket.h \
           clamonacc/fanotif/fanotif.h \
           clamonacc/inotif/hash.h \
           clamonacc/inotif/inotif.h \
           clamonacc/misc/priv_fts.h \
           clamonacc/misc/utils.h \
           clamonacc/scan/onas_queue.h \
           clamonacc/scan/thread.h \
           libclamav/7z/7z.h \
           libclamav/7z/7zAlloc.h \
           libclamav/7z/7zBuf.h \
           libclamav/7z/7zCrc.h \
           libclamav/7z/7zFile.h \
           libclamav/7z/7zVersion.h \
           libclamav/7z/Alloc.h \
           libclamav/7z/Bcj2.h \
           libclamav/7z/Bra.h \
           libclamav/7z/CpuArch.h \
           libclamav/7z/Delta.h \
           libclamav/7z/Lzma2Dec.h \
           libclamav/7z/LzmaDec.h \
           libclamav/7z/Ppmd.h \
           libclamav/7z/Ppmd7.h \
           libclamav/7z/RotateDefs.h \
           libclamav/7z/Types.h \
           libclamav/7z/Xz.h \
           libclamav/7z/XzCrc64.h \
           libclamav/c++/ClamBCDiagnostics.h \
           libclamav/c++/ClamBCModule.h \
           libclamav/jsparse/js-norm.h \
           libclamav/jsparse/lexglobal.h \
           libclamav/jsparse/textbuf.h \
           libclamav/lzw/lzwdec.h \
           libclamav/nsis/bzlib_private.h \
           libclamav/nsis/nsis_bzlib.h \
           libclamav/nsis/nsis_zconf.h \
           libclamav/nsis/nsis_zlib.h \
           libclamav/nsis/nsis_zutil.h \
           libclamav/nsis/nulsft.h \
           libclamav/regex/cclass.h \
           libclamav/regex/cname.h \
           libclamav/regex/regex.h \
           libclamav/regex/regex2.h \
           libclamav/regex/utils.h \
           libclammspack/mspack/cab.h \
           libclammspack/mspack/chm.h \
           libclammspack/mspack/crc32.h \
           libclammspack/mspack/des.h \
           libclammspack/mspack/hlp.h \
           libclammspack/mspack/kwaj.h \
           libclammspack/mspack/lit.h \
           libclammspack/mspack/lzss.h \
           libclammspack/mspack/lzx.h \
           libclammspack/mspack/macros.h \
           libclammspack/mspack/mspack.h \
           libclammspack/mspack/mszip.h \
           libclammspack/mspack/oab.h \
           libclammspack/mspack/qtm.h \
           libclammspack/mspack/readbits.h \
           libclammspack/mspack/readhuff.h \
           libclammspack/mspack/sha.h \
           libclammspack/mspack/system.h \
           libclammspack/mspack/szdd.h \
           libclammspack/test/error.h \
           libclammspack/test/md5.h \
           libclammspack/test/md5_fh.h \
           win32/compat/dirent.h \
           win32/compat/gettimeofday.h \
           win32/compat/libgen.h \
           win32/compat/net.h \
           win32/compat/random.h \
           win32/compat/resolv.h \
           win32/compat/snprintf.h \
           win32/compat/utf8_util.h \
           win32/compat/w32_errno.h \
           win32/compat/w32_stat.h \
           libclamav/jsparse/generated/keywords.h \
           libclamav/jsparse/generated/operators.h \
           unit_tests/input/pe_allmatch/test-exe-src/extract.h
LEXSOURCES += libclamav/yara_lexer.l
YACCSOURCES += libclamav/yara_grammar.y
SOURCES += test_clamav.cpp \
           clamav-milter/allow_list.c \
           clamav-milter/clamav-milter.c \
           clamav-milter/clamfi.c \
           clamav-milter/connpool.c \
           clamav-milter/netcode.c \
           clambc/bcrun.c \
           clamconf/clamconf.c \
           clamd/clamd.c \
           clamd/clamd_others.c \
           clamd/localserver.c \
           clamd/scanner.c \
           clamd/server-th.c \
           clamd/session.c \
           clamd/tcpserver.c \
           clamd/thrmgr.c \
           clamdscan/clamdscan.c \
           clamdscan/client.c \
           clamdscan/proto.c \
           clamdtop/clamdtop.c \
           clamonacc/clamonacc.c \
           clamscan/clamscan.c \
           clamscan/manager.c \
           clamsubmit/clamsubmit.c \
           cmake/CheckFDPassing.c \
           cmake/CheckFileOffsetBits.c \
           cmake/CheckSignedRightShift.c \
           cmake/CheckStructPacking_PRAGMA_PACK.c \
           cmake/CheckStructPacking_PRAGMA_PACK_HPPA.c \
           cmake/CheckUnamePosix.c \
           cmake/TestInline.c \
           common/actions.c \
           common/cert_util.c \
           common/clamdcom.c \
           common/exeScanner.c \
           common/getopt.c \
           common/hostid.c \
           common/idmef_logging.c \
           common/misc.c \
           common/optparser.c \
           common/output.c \
           common/scanmem.c \
           common/service.c \
           common/tar.c \
           examples/ex_basic_scandesc.c \
           examples/ex_cl_cvdunpack.c \
           examples/ex_file_inspection_callback.c \
           examples/ex_prescan_callback.c \
           freshclam/execute.c \
           freshclam/freshclam.c \
           freshclam/notify.c \
           fuzz/clamav_dbload_fuzzer.cpp \
           fuzz/clamav_scanfile_fuzzer.cpp \
           fuzz/clamav_scanmap_fuzzer.cpp \
           fuzz/standalone_fuzz_target_runner.cpp \
           libclamav/7z_iface.c \
           libclamav/adc.c \
           libclamav/apm.c \
           libclamav/arc4.c \
           libclamav/asn1.c \
           libclamav/aspack.c \
           libclamav/autoit.c \
           libclamav/binhex.c \
           libclamav/blob.c \
           libclamav/bytecode.c \
           libclamav/bytecode_api.c \
           libclamav/bytecode_api_decl.c \
           libclamav/bytecode_detect.c \
           libclamav/bytecode_nojit.c \
           libclamav/bytecode_vm.c \
           libclamav/cache.c \
           libclamav/conv.c \
           libclamav/cpio.c \
           libclamav/crtmgr.c \
           libclamav/crypto.c \
           libclamav/cvd.c \
           libclamav/dconf.c \
           libclamav/disasm.c \
           libclamav/dlp.c \
           libclamav/dmg.c \
           libclamav/dsig.c \
           libclamav/egg.c \
           libclamav/elf.c \
           libclamav/entconv.c \
           libclamav/events.c \
           libclamav/execs.c \
           libclamav/explode.c \
           libclamav/filetypes.c \
           libclamav/filtering.c \
           libclamav/fmap.c \
           libclamav/fpu.c \
           libclamav/fsg.c \
           libclamav/gif.c \
           libclamav/gpt.c \
           libclamav/hashtab.c \
           libclamav/hfsplus.c \
           libclamav/hostid_internal.c \
           libclamav/htmlnorm.c \
           libclamav/hwp.c \
           libclamav/inflate64.c \
           libclamav/iowrap.c \
           libclamav/is_tar.c \
           libclamav/ishield.c \
           libclamav/iso9660.c \
           libclamav/jpeg.c \
           libclamav/json_api.c \
           libclamav/libclamav_main.c \
           libclamav/libmspack.c \
           libclamav/line.c \
           libclamav/lzma_iface.c \
           libclamav/macho.c \
           libclamav/matcher-ac.c \
           libclamav/matcher-bm.c \
           libclamav/matcher-byte-comp.c \
           libclamav/matcher-hash.c \
           libclamav/matcher-pcre.c \
           libclamav/matcher.c \
           libclamav/mbox.c \
           libclamav/mbr.c \
           libclamav/message.c \
           libclamav/mew.c \
           libclamav/mpool.c \
           libclamav/msdoc.c \
           libclamav/msexpand.c \
           libclamav/msxml.c \
           libclamav/msxml_parser.c \
           libclamav/ole2_extract.c \
           libclamav/ooxml.c \
           libclamav/openioc.c \
           libclamav/others.c \
           libclamav/others_common.c \
           libclamav/packlibs.c \
           libclamav/partition_intersection.c \
           libclamav/pdf.c \
           libclamav/pdfdecode.c \
           libclamav/pdfng.c \
           libclamav/pe.c \
           libclamav/pe_icons.c \
           libclamav/perflogging.c \
           libclamav/petite.c \
           libclamav/phish_allow_list.c \
           libclamav/phish_domaincheck_db.c \
           libclamav/phishcheck.c \
           libclamav/png.c \
           libclamav/qsort.c \
           libclamav/readdb.c \
           libclamav/rebuildpe.c \
           libclamav/regex_list.c \
           libclamav/regex_pcre.c \
           libclamav/regex_suffix.c \
           libclamav/rijndael.c \
           libclamav/rtf.c \
           libclamav/scanners.c \
           libclamav/sf_base64decode.c \
           libclamav/sis.c \
           libclamav/special.c \
           libclamav/spin.c \
           libclamav/stats.c \
           libclamav/stats_json.c \
           libclamav/str.c \
           libclamav/strlcat.c \
           libclamav/swf.c \
           libclamav/table.c \
           libclamav/text.c \
           libclamav/textdet.c \
           libclamav/textnorm.c \
           libclamav/tiff.c \
           libclamav/tnef.c \
           libclamav/udf.c \
           libclamav/unarj.c \
           libclamav/uniq.c \
           libclamav/unsp.c \
           libclamav/untar.c \
           libclamav/unzip.c \
           libclamav/upack.c \
           libclamav/upx.c \
           libclamav/uuencode.c \
           libclamav/vba_extract.c \
           libclamav/version.c \
           libclamav/wwunpack.c \
           libclamav/www.c \
           libclamav/xar.c \
           libclamav/xdp.c \
           libclamav/xlm_extract.c \
           libclamav/xz_iface.c \
           libclamav/yara_arena.c \
           libclamav/yara_compiler.c \
           libclamav/yara_exec.c \
           libclamav/yara_grammar.c \
           libclamav/yara_hash.c \
           libclamav/yara_lexer.c \
           libclamav/yara_parser.c \
           libclamav/yc.c \
           libclamunrar/arccmt.cpp \
           libclamunrar/archive.cpp \
           libclamunrar/arcread.cpp \
           libclamunrar/blake2s.cpp \
           libclamunrar/blake2s_sse.cpp \
           libclamunrar/blake2sp.cpp \
           libclamunrar/cmddata.cpp \
           libclamunrar/cmdfilter.cpp \
           libclamunrar/cmdmix.cpp \
           libclamunrar/coder.cpp \
           libclamunrar/consio.cpp \
           libclamunrar/crc.cpp \
           libclamunrar/crypt.cpp \
           libclamunrar/crypt1.cpp \
           libclamunrar/crypt2.cpp \
           libclamunrar/crypt3.cpp \
           libclamunrar/crypt5.cpp \
           libclamunrar/dll.cpp \
           libclamunrar/encname.cpp \
           libclamunrar/errhnd.cpp \
           libclamunrar/extinfo.cpp \
           libclamunrar/extract.cpp \
           libclamunrar/filcreat.cpp \
           libclamunrar/file.cpp \
           libclamunrar/filefn.cpp \
           libclamunrar/filestr.cpp \
           libclamunrar/find.cpp \
           libclamunrar/getbits.cpp \
           libclamunrar/global.cpp \
           libclamunrar/hardlinks.cpp \
           libclamunrar/hash.cpp \
           libclamunrar/headers.cpp \
           libclamunrar/isnt.cpp \
           libclamunrar/list.cpp \
           libclamunrar/log.cpp \
           libclamunrar/match.cpp \
           libclamunrar/model.cpp \
           libclamunrar/options.cpp \
           libclamunrar/pathfn.cpp \
           libclamunrar/qopen.cpp \
           libclamunrar/rar.cpp \
           libclamunrar/rarpch.cpp \
           libclamunrar/rarvm.cpp \
           libclamunrar/rawread.cpp \
           libclamunrar/rdwrfn.cpp \
           libclamunrar/recvol.cpp \
           libclamunrar/recvol3.cpp \
           libclamunrar/recvol5.cpp \
           libclamunrar/resource.cpp \
           libclamunrar/rijndael.cpp \
           libclamunrar/rs.cpp \
           libclamunrar/rs16.cpp \
           libclamunrar/scantree.cpp \
           libclamunrar/secpassword.cpp \
           libclamunrar/sha1.cpp \
           libclamunrar/sha256.cpp \
           libclamunrar/smallfn.cpp \
           libclamunrar/strfn.cpp \
           libclamunrar/strlist.cpp \
           libclamunrar/suballoc.cpp \
           libclamunrar/system.cpp \
           libclamunrar/threadmisc.cpp \
           libclamunrar/threadpool.cpp \
           libclamunrar/timefn.cpp \
           libclamunrar/ui.cpp \
           libclamunrar/uicommon.cpp \
           libclamunrar/uiconsole.cpp \
           libclamunrar/uisilent.cpp \
           libclamunrar/ulinks.cpp \
           libclamunrar/unicode.cpp \
           libclamunrar/unpack.cpp \
           libclamunrar/unpack15.cpp \
           libclamunrar/unpack20.cpp \
           libclamunrar/unpack30.cpp \
           libclamunrar/unpack50.cpp \
           libclamunrar/unpack50frag.cpp \
           libclamunrar/unpack50mt.cpp \
           libclamunrar/unpackinline.cpp \
           libclamunrar/uowners.cpp \
           libclamunrar/volume.cpp \
           libclamunrar/win32acl.cpp \
           libclamunrar/win32lnk.cpp \
           libclamunrar/win32stm.cpp \
           libclamunrar_iface/unrar_iface.cpp \
           libfreshclam/dns.c \
           libfreshclam/libfreshclam.c \
           libfreshclam/libfreshclam_internal.c \
           libfreshclam/libfreshclam_main.c \
           sigtool/sigtool.c \
           sigtool/vba.c \
           unit_tests/check_bytecode.c \
           unit_tests/check_clamav.c \
           unit_tests/check_clamav_skip.c \
           unit_tests/check_clamd.c \
           unit_tests/check_disasm.c \
           unit_tests/check_fpu_endian.c \
           unit_tests/check_htmlnorm.c \
           unit_tests/check_jsnorm.c \
           unit_tests/check_matchers.c \
           unit_tests/check_regex.c \
           unit_tests/check_str.c \
           unit_tests/check_uniq.c \
           clamonacc/c-thread-pool/thpool.c \
           clamonacc/client/client.c \
           clamonacc/client/communication.c \
           clamonacc/client/protocol.c \
           clamonacc/client/socket.c \
           clamonacc/fanotif/fanotif.c \
           clamonacc/inotif/hash.c \
           clamonacc/inotif/inotif.c \
           clamonacc/misc/fts.c \
           clamonacc/misc/utils.c \
           clamonacc/scan/onas_queue.c \
           clamonacc/scan/thread.c \
           common/linux/cert_util_linux.c \
           common/win/cert_util_win.c \
           examples/fileprop_analysis/embedpe_sample.c \
           examples/fileprop_analysis/ftype_sample.c \
           examples/fileprop_analysis/notpdf_sample.c \
           examples/fileprop_analysis/onlype_sample.c \
           examples/fileprop_analysis/sandbox.c \
           libclamav/7z/7zAlloc.c \
           libclamav/7z/7zBuf.c \
           libclamav/7z/7zBuf2.c \
           libclamav/7z/7zCrc.c \
           libclamav/7z/7zCrcOpt.c \
           libclamav/7z/7zDec.c \
           libclamav/7z/7zFile.c \
           libclamav/7z/7zIn.c \
           libclamav/7z/7zStream.c \
           libclamav/7z/Bcj2.c \
           libclamav/7z/Bra.c \
           libclamav/7z/Bra86.c \
           libclamav/7z/BraIA64.c \
           libclamav/7z/CpuArch.c \
           libclamav/7z/Delta.c \
           libclamav/7z/Lzma2Dec.c \
           libclamav/7z/LzmaDec.c \
           libclamav/7z/Ppmd7.c \
           libclamav/7z/Ppmd7Dec.c \
           libclamav/7z/Xz.c \
           libclamav/7z/XzCrc64.c \
           libclamav/7z/XzDec.c \
           libclamav/7z/XzIn.c \
           libclamav/c++/bytecode2llvm.cpp \
           libclamav/c++/detect.cpp \
           libclamav/jsparse/js-norm.c \
           libclamav/lzw/lzwdec.c \
           libclamav/nsis/bzlib.c \
           libclamav/nsis/infblock.c \
           libclamav/nsis/nulsft.c \
           libclamav/regex/engine.c \
           libclamav/regex/regcomp.c \
           libclamav/regex/regerror.c \
           libclamav/regex/regexec.c \
           libclamav/regex/regfree.c \
           libclamav/regex/strlcpy.c \
           libclammspack/examples/cabd_memory.c \
           libclammspack/examples/cabrip.c \
           libclammspack/examples/chmextract.c \
           libclammspack/examples/msexpand.c \
           libclammspack/examples/multifh.c \
           libclammspack/examples/oabextract.c \
           libclammspack/mspack/cabc.c \
           libclammspack/mspack/cabd.c \
           libclammspack/mspack/chmc.c \
           libclammspack/mspack/chmd.c \
           libclammspack/mspack/crc32.c \
           libclammspack/mspack/debug.c \
           libclammspack/mspack/hlpc.c \
           libclammspack/mspack/hlpd.c \
           libclammspack/mspack/kwajc.c \
           libclammspack/mspack/kwajd.c \
           libclammspack/mspack/litc.c \
           libclammspack/mspack/litd.c \
           libclammspack/mspack/lzssd.c \
           libclammspack/mspack/lzxc.c \
           libclammspack/mspack/lzxd.c \
           libclammspack/mspack/mszipc.c \
           libclammspack/mspack/mszipd.c \
           libclammspack/mspack/oabc.c \
           libclammspack/mspack/oabd.c \
           libclammspack/mspack/qtmc.c \
           libclammspack/mspack/qtmd.c \
           libclammspack/mspack/system.c \
           libclammspack/mspack/szddc.c \
           libclammspack/mspack/szddd.c \
           libclammspack/test/cabd_md5.c \
           libclammspack/test/cabd_test.c \
           libclammspack/test/chmd_find.c \
           libclammspack/test/chmd_md5.c \
           libclammspack/test/chmd_order.c \
           libclammspack/test/chmd_test.c \
           libclammspack/test/chminfo.c \
           libclammspack/test/kwajd_test.c \
           libclammspack/test/md5.c \
           win32/compat/dirent.c \
           win32/compat/gettimeofday.c \
           win32/compat/glob.c \
           win32/compat/libgen.c \
           win32/compat/net.c \
           win32/compat/random.c \
           win32/compat/resolv.c \
           win32/compat/snprintf.c \
           win32/compat/strptime.c \
           win32/compat/utf8_util.c \
           win32/compat/w32_errno.c \
           win32/compat/w32_errno_defs.c \
           win32/compat/w32_stat.c \
           examples/fileprop_analysis/old/embedpe_sample.c \
           examples/fileprop_analysis/old/ftype_sample.c \
           examples/fileprop_analysis/old/notpdf_sample.c \
           examples/fileprop_analysis/old/onlype_sample.c \
           examples/fileprop_analysis/old/sandbox.c \
           build/CMakeFiles/3.28.3/CompilerIdC/CMakeCCompilerId.c \
           build/CMakeFiles/3.28.3/CompilerIdCXX/CMakeCXXCompilerId.cpp \
           unit_tests/input/pe_allmatch/test-exe-src/test.c
TRANSLATIONS += build/CMakeFiles/check.dir/compiler_depend.ts \
                build/CMakeFiles/Continuous.dir/compiler_depend.ts \
                build/CMakeFiles/ContinuousBuild.dir/compiler_depend.ts \
                build/CMakeFiles/ContinuousConfigure.dir/compiler_depend.ts \
                build/CMakeFiles/ContinuousCoverage.dir/compiler_depend.ts \
                build/CMakeFiles/ContinuousMemCheck.dir/compiler_depend.ts \
                build/CMakeFiles/ContinuousStart.dir/compiler_depend.ts \
                build/CMakeFiles/ContinuousSubmit.dir/compiler_depend.ts \
                build/CMakeFiles/ContinuousTest.dir/compiler_depend.ts \
                build/CMakeFiles/ContinuousUpdate.dir/compiler_depend.ts \
                build/CMakeFiles/Experimental.dir/compiler_depend.ts \
                build/CMakeFiles/ExperimentalBuild.dir/compiler_depend.ts \
                build/CMakeFiles/ExperimentalConfigure.dir/compiler_depend.ts \
                build/CMakeFiles/ExperimentalCoverage.dir/compiler_depend.ts \
                build/CMakeFiles/ExperimentalMemCheck.dir/compiler_depend.ts \
                build/CMakeFiles/ExperimentalStart.dir/compiler_depend.ts \
                build/CMakeFiles/ExperimentalSubmit.dir/compiler_depend.ts \
                build/CMakeFiles/ExperimentalTest.dir/compiler_depend.ts \
                build/CMakeFiles/ExperimentalUpdate.dir/compiler_depend.ts \
                build/CMakeFiles/Nightly.dir/compiler_depend.ts \
                build/CMakeFiles/NightlyBuild.dir/compiler_depend.ts \
                build/CMakeFiles/NightlyConfigure.dir/compiler_depend.ts \
                build/CMakeFiles/NightlyCoverage.dir/compiler_depend.ts \
                build/CMakeFiles/NightlyMemCheck.dir/compiler_depend.ts \
                build/CMakeFiles/NightlyMemoryCheck.dir/compiler_depend.ts \
                build/CMakeFiles/NightlyStart.dir/compiler_depend.ts \
                build/CMakeFiles/NightlySubmit.dir/compiler_depend.ts \
                build/CMakeFiles/NightlyTest.dir/compiler_depend.ts \
                build/CMakeFiles/NightlyUpdate.dir/compiler_depend.ts \
                build/clamav-milter/CMakeFiles/clamav-milter.dir/compiler_depend.ts \
                build/clambc/CMakeFiles/clambc.dir/compiler_depend.ts \
                build/clamconf/CMakeFiles/clamconf.dir/compiler_depend.ts \
                build/clamd/CMakeFiles/clamd.dir/compiler_depend.ts \
                build/clamdscan/CMakeFiles/clamdscan.dir/compiler_depend.ts \
                build/clamdtop/CMakeFiles/clamdtop.dir/compiler_depend.ts \
                build/clamonacc/CMakeFiles/clamonacc.dir/compiler_depend.ts \
                build/clamscan/CMakeFiles/clamscan.dir/compiler_depend.ts \
                build/clamsubmit/CMakeFiles/clamsubmit.dir/compiler_depend.ts \
                build/common/CMakeFiles/common.dir/compiler_depend.ts \
                build/freshclam/CMakeFiles/freshclam-bin.dir/compiler_depend.ts \
                build/libclamav/CMakeFiles/bytecode_runtime.dir/compiler_depend.ts \
                build/libclamav/CMakeFiles/clamav.dir/compiler_depend.ts \
                build/libclamav/CMakeFiles/lzma_sdk.dir/compiler_depend.ts \
                build/libclamav/CMakeFiles/regex.dir/compiler_depend.ts \
                build/libclamav/CMakeFiles/yara.dir/compiler_depend.ts \
                build/libclamav_rust/CMakeFiles/clamav_rust_target.dir/compiler_depend.ts \
                build/libclammspack/CMakeFiles/clammspack.dir/compiler_depend.ts \
                build/libclamunrar/CMakeFiles/clamunrar.dir/compiler_depend.ts \
                build/libclamunrar_iface/CMakeFiles/clamunrar_iface.dir/compiler_depend.ts \
                build/libfreshclam/CMakeFiles/freshclam.dir/compiler_depend.ts \
                build/sigtool/CMakeFiles/sigtool.dir/compiler_depend.ts \
                build/unit_tests/CMakeFiles/check_clamav.dir/compiler_depend.ts \
                build/unit_tests/CMakeFiles/check_clamd.dir/compiler_depend.ts \
                build/unit_tests/CMakeFiles/check_fpu_endian.dir/compiler_depend.ts \
                build/unit_tests/input/CMakeFiles/tgt_clam-aspack.exe.dir/compiler_depend.ts \
                build/unit_tests/input/CMakeFiles/tgt_clam-fsg.exe.dir/compiler_depend.ts \
                build/unit_tests/input/CMakeFiles/tgt_clam-mew.exe.dir/compiler_depend.ts \
                build/unit_tests/input/CMakeFiles/tgt_clam-nsis.exe.dir/compiler_depend.ts \
                build/unit_tests/input/CMakeFiles/tgt_clam-pespin.exe.dir/compiler_depend.ts \
                build/unit_tests/input/CMakeFiles/tgt_clam-petite.exe.dir/compiler_depend.ts \
                build/unit_tests/input/CMakeFiles/tgt_clam-upack.exe.dir/compiler_depend.ts \
                build/unit_tests/input/CMakeFiles/tgt_clam-upx.exe.dir/compiler_depend.ts \
                build/unit_tests/input/CMakeFiles/tgt_clam-v2.rar.dir/compiler_depend.ts \
                build/unit_tests/input/CMakeFiles/tgt_clam-v3.rar.dir/compiler_depend.ts \
                build/unit_tests/input/CMakeFiles/tgt_clam-wwpack.exe.dir/compiler_depend.ts \
                build/unit_tests/input/CMakeFiles/tgt_clam-yc.exe.dir/compiler_depend.ts \
                build/unit_tests/input/CMakeFiles/tgt_clam.7z.dir/compiler_depend.ts \
                build/unit_tests/input/CMakeFiles/tgt_clam.arj.dir/compiler_depend.ts \
                build/unit_tests/input/CMakeFiles/tgt_clam.bin-be.cpio.dir/compiler_depend.ts \
                build/unit_tests/input/CMakeFiles/tgt_clam.bin-le.cpio.dir/compiler_depend.ts \
                build/unit_tests/input/CMakeFiles/tgt_clam.bz2.zip.dir/compiler_depend.ts \
                build/unit_tests/input/CMakeFiles/tgt_clam.cab.dir/compiler_depend.ts \
                build/unit_tests/input/CMakeFiles/tgt_clam.chm.dir/compiler_depend.ts \
                build/unit_tests/input/CMakeFiles/tgt_clam.d64.zip.dir/compiler_depend.ts \
                build/unit_tests/input/CMakeFiles/tgt_clam.ea05.exe.dir/compiler_depend.ts \
                build/unit_tests/input/CMakeFiles/tgt_clam.ea06.exe.dir/compiler_depend.ts \
                build/unit_tests/input/CMakeFiles/tgt_clam.exe.2007.one.dir/compiler_depend.ts \
                build/unit_tests/input/CMakeFiles/tgt_clam.exe.2010.one.dir/compiler_depend.ts \
                build/unit_tests/input/CMakeFiles/tgt_clam.exe.binhex.dir/compiler_depend.ts \
                build/unit_tests/input/CMakeFiles/tgt_clam.exe.bz2.dir/compiler_depend.ts \
                build/unit_tests/input/CMakeFiles/tgt_clam.exe.dir/compiler_depend.ts \
                build/unit_tests/input/CMakeFiles/tgt_clam.exe.html.dir/compiler_depend.ts \
                build/unit_tests/input/CMakeFiles/tgt_clam.exe.mbox.base64.dir/compiler_depend.ts \
                build/unit_tests/input/CMakeFiles/tgt_clam.exe.mbox.uu.dir/compiler_depend.ts \
                build/unit_tests/input/CMakeFiles/tgt_clam.exe.rtf.dir/compiler_depend.ts \
                build/unit_tests/input/CMakeFiles/tgt_clam.exe.szdd.dir/compiler_depend.ts \
                build/unit_tests/input/CMakeFiles/tgt_clam.exe.webapp-export.one.dir/compiler_depend.ts \
                build/unit_tests/input/CMakeFiles/tgt_clam.exe_and_mail.tar.gz.dir/compiler_depend.ts \
                build/unit_tests/input/CMakeFiles/tgt_clam.impl.zip.dir/compiler_depend.ts \
                build/unit_tests/input/CMakeFiles/tgt_clam.iso.dir/compiler_depend.ts \
                build/unit_tests/input/CMakeFiles/tgt_clam.mail.dir/compiler_depend.ts \
                build/unit_tests/input/CMakeFiles/tgt_clam.newc.cpio.dir/compiler_depend.ts \
                build/unit_tests/input/CMakeFiles/tgt_clam.odc.cpio.dir/compiler_depend.ts \
                build/unit_tests/input/CMakeFiles/tgt_clam.ole.doc.dir/compiler_depend.ts \
                build/unit_tests/input/CMakeFiles/tgt_clam.pdf.dir/compiler_depend.ts \
                build/unit_tests/input/CMakeFiles/tgt_clam.ppt.dir/compiler_depend.ts \
                build/unit_tests/input/CMakeFiles/tgt_clam.sis.dir/compiler_depend.ts \
                build/unit_tests/input/CMakeFiles/tgt_clam.tar.gz.dir/compiler_depend.ts \
                build/unit_tests/input/CMakeFiles/tgt_clam.tnef.dir/compiler_depend.ts \
                build/unit_tests/input/CMakeFiles/tgt_clam.zip.dir/compiler_depend.ts \
                build/unit_tests/input/CMakeFiles/tgt_clam_cache_emax.tgz.dir/compiler_depend.ts \
                build/unit_tests/input/CMakeFiles/tgt_clam_IScab_ext.exe.dir/compiler_depend.ts \
                build/unit_tests/input/CMakeFiles/tgt_clam_IScab_int.exe.dir/compiler_depend.ts \
                build/unit_tests/input/CMakeFiles/tgt_clam_ISmsi_ext.exe.dir/compiler_depend.ts \
                build/unit_tests/input/CMakeFiles/tgt_clam_ISmsi_int.exe.dir/compiler_depend.ts \
                build/unit_tests/input/CMakeFiles/tgt_clamav_hdb_scanfiles.dir/compiler_depend.ts \
                build/unit_tests/input/CMakeFiles/tgt_clamjol.iso.dir/compiler_depend.ts
