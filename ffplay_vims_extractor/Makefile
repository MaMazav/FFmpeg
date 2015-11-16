#This is not built with the upper folder, should execute Make here

all: ffplay_vims_extractor
	@echo \******************************************************************
	@echo "*               Build done. Execute by:                          *"
	@echo "* LD_LIBRARY_PATH=./shared ./ffplay_vims_extractor \<arguments\> *"
	@echo \******************************************************************

FFMPEG_SRC=..
FFMPEG_BIN=~/bin

clean:
	rm -rf ffplay_vims_extractor ffplay_vims_extractor.o shared/

ffplay_vims_extractor: ffplay_vims_extractor.o ./shared/libffplay_shared.so ./shared/libavcodec.so ./shared/libavdevice.so ./shared/libavfilter.so ./shared/libavformat.so ./shared/libavutil.so  ./shared/libpostproc.so ./shared/libswresample.so ./shared/libswscale.so
	g++ -o ffplay_vims_extractor ffplay_vims_extractor.o -L./shared -lffplay_shared -lavcodec -lavdevice -lavfilter -lavformat -lavutil -lpostproc -lswresample -lswscale

ffplay_vims_extractor.o: ffplay_vims_extractor.cpp $(FFMPEG_SRC)/ffplay_entrypoint.h
	g++ -fPIC -c -o ffplay_vims_extractor.o -I$(FFMPEG_SRC) ffplay_vims_extractor.cpp

./shared/libffplay_shared.so: $(FFMPEG_SRC)/libffplay_shared ./shared
	cp $(FFMPEG_SRC)/libffplay_shared ./shared/libffplay_shared.so

./shared/libavcodec.so: $(FFMPEG_SRC)/libavcodec/libavcodec.so ./shared
	cp $(FFMPEG_SRC)/libavcodec/libavcodec.so* ./shared/

./shared/libavdevice.so: $(FFMPEG_SRC)/libavdevice/libavdevice.so ./shared
	cp $(FFMPEG_SRC)/libavdevice/libavdevice.so* ./shared/

./shared/libavfilter.so: $(FFMPEG_SRC)/libavfilter/libavfilter.so ./shared
	cp $(FFMPEG_SRC)/libavfilter/libavfilter.so* ./shared/

./shared/libavformat.so: $(FFMPEG_SRC)/libavformat/libavformat.so ./shared
	cp $(FFMPEG_SRC)/libavformat/libavformat.so* ./shared/

./shared/libavutil.so: $(FFMPEG_SRC)/libavutil/libavutil.so ./shared
	cp $(FFMPEG_SRC)/libavutil/libavutil.so* ./shared/

./shared/libpostproc.so: $(FFMPEG_SRC)/libpostproc/libpostproc.so ./shared
	cp $(FFMPEG_SRC)/libpostproc/libpostproc.so* ./shared/

./shared/libswresample.so: $(FFMPEG_SRC)/libswresample/libswresample.so ./shared
	cp $(FFMPEG_SRC)/libswresample/libswresample.so* ./shared/

./shared/libswscale.so: $(FFMPEG_SRC)/libswscale/libswscale.so ./shared
	cp $(FFMPEG_SRC)/libswscale/libswscale.so* ./shared/

./shared:
	mkdir -p ./shared
