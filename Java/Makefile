DIR=$(shell pwd)
JAVA_DIR=${JAVA_HOME}
#CINC_DIR=/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include
CINC_DIR=/usr/include

JNI_LIB=libCore.jnilib

JNI_SRCS=com_strakswallet_core_BRCoreAddress.c \
	com_strakswallet_core_BRCoreChainParams.c \
	com_strakswallet_core_BRCoreJniReference.c \
	com_strakswallet_core_BRCoreKey.c \
	com_strakswallet_core_BRCoreMasterPubKey.c \
	com_strakswallet_core_BRCoreMerkleBlock.c \
	com_strakswallet_core_BRCorePaymentProtocol.c \
	com_strakswallet_core_BRCorePeer.c \
	com_strakswallet_core_BRCorePeerManager.c \
	com_strakswallet_core_BRCoreTransaction.c \
	com_strakswallet_core_BRCoreTransactionInput.c \
	com_strakswallet_core_BRCoreTransactionOutput.c \
	com_strakswallet_core_BRCoreWallet.c \
	BRCoreJni.c

JNI_OBJS=$(JNI_SRCS:.c=.o)

# JNI Header Files that we are interest in keeping (that are not empty)
JNI_HDRS=$(JNI_SRCS:.c=.h)

JAVA_SRCS=root/com/strakswallet/core/BRCoreAddress.java \
	root/com/strakswallet/core/BRCoreChainParams.java \
	root/com/strakswallet/core/BRCoreJniReference.java \
	root/com/strakswallet/core/BRCoreKey.java \
	root/com/strakswallet/core/BRCoreMasterPubKey.java \
	root/com/strakswallet/core/BRCoreMerkleBlock.java \
	root/com/strakswallet/core/BRCorePaymentProtocolEncryptedMessage.java \
	root/com/strakswallet/core/BRCorePaymentProtocolInvoiceRequest.java \
	root/com/strakswallet/core/BRCorePaymentProtocolMessage.java \
	root/com/strakswallet/core/BRCorePaymentProtocolPayment.java \
	root/com/strakswallet/core/BRCorePaymentProtocolACK.java \
	root/com/strakswallet/core/BRCorePaymentProtocolRequest.java \
	root/com/strakswallet/core/BRCorePeer.java \
	root/com/strakswallet/core/BRCorePeerManager.java \
	root/com/strakswallet/core/BRCoreTransaction.java \
	root/com/strakswallet/core/BRCoreTransactionInput.java \
	root/com/strakswallet/core/BRCoreTransactionOutput.java \
	root/com/strakswallet/core/BRCoreWallet.java \
	root/com/strakswallet/core/BRCoreWalletManager.java \
	root/com/strakswallet/core/test/BRWalletManager.java

JAVA_OBJS=$(JAVA_SRCS:.java=.class)

CORE_SRCS=../BRAddress.c \
	../BRBIP32Sequence.c \
	../BRBIP38Key.c \
	../BRBIP39Mnemonic.c \
	../BRBase58.c \
	../BRBech32.c \
	../BRBloomFilter.c \
	../BRCrypto.c \
	../BRKey.c \
	../BRMerkleBlock.c \
	../BRPaymentProtocol.c \
	../BRPeer.c \
	../BRPeerManager.c \
	../BRSet.c \
	../BRTransaction.c \
	../BRWallet.c \
	../bcash/BRBCashAddr.c

CORE_OBJS=$(CORE_SRCS:.c=.o)

CFLAGS=-I$(JAVA_HOME)/include \
	-I$(JAVA_HOME)/include/darwin \
	-I$(CINC_DIR) \
	-I$(CINC_DIR)/malloc \
	-I.. \
	-I../secp256k1 \
	-Wno-nullability-completeness -Wno-format-extra-args -Wno-unknown-warning-option

compile: $(JNI_LIB) java_comp

test: $(JNI_LIB) java_comp
	java -Xss1m -Dwallet.test -classpath build -Djava.library.path=. \
		 com.strakswallet.core.test.BRWalletManager $(ARGS) # -D.

debug: $(JNI_LIB) java_comp
	java -Xss1m -Xdebug -Xrunjdwp:transport=dt_socket,address=8008,server=y,suspend=n \
		 -Dwallet.test -classpath build -Djava.library.path=. \
		 com.strakswallet.core.test.BRWalletManager $(ARGS) # -D.

$(JNI_LIB): $(JNI_OBJS) $(CORE_OBJS)
	cc -dynamiclib -o $(JNI_LIB) $(JNI_OBJS) $(CORE_OBJS)

java_comp:	FORCE
	@mkdir -p build
	javac -d build $(JAVA_SRCS)

jni_hdr: java_comp
	@(cd build/com/strakswallet/core; \
	  for class in BRCore*.class; do \
	      javah -jni -d $(DIR) -classpath $(DIR)/build com.strakswallet.core.$${class%%.class}; \
	  done)
	@rm -f com_strakswallet_core_BRCoreWalletManager.h com_strakswallet_core_BRCore*_*.h .h

#            if [[ "$${class}" != "*\"$\"*" ]]; then
#           fi

clean:
	rm -rf build $(JNI_OBJS) $(CORE_OBJS) $(JAVA_OBJS) $(JNI_LIB)

FORCE:

#	-Wno-nullability-completeness


# Generate Headers:
# 	javac Foo.java
# 	javah -jni -d <location> Foo
# Implement Foo.c
# Generate Foo.so
# 	cc -I<path to jni.h> -I<path to jni_md.h> -I<path to std> -c Foo.c
# 	cc -dynamiclib -o libFoo.jnilib Foo.o Bar.o

# 	<path-to-jni-md>=/Library/Java/JavaVirtualMachines/jdk1.8.0_151.jdk/Contents/Home/include/darwin
# 	<path-to-jni>=/Library/Java/JavaVirtualMachines/jdk1.8.0_151.jdk/Contents/Home/include
# 	<path-to-std>=/…/Xcode.app/Contents/Dev…/Platforms/MacOSX.platform/Dev…/SDKs/MacOSX.sdk/usr/include
# Run Foo
# 	java -Djava.library.path=/Users/ebg Foo
#

# (cd ${APP}/app/build/intermediates/classes/debug/com/strakswallet/core; for class in BRCore*.class; do \
#     javah -jni -d ${APP}/app/src/main/cpp/strakswallet-core/Java/ \
#	-classpath ${APP}/app/build/intermediates/classes/debug/ \
#	com.strakswallet.core.${class%%.class}; \
#	done)
# 15RBcXQMTfebbAfUFeBbcDfs1fVvPayWdU
