FROM jett59/mykonos-binutils AS build
RUN apk add --no-cache build-base flex bison
COPY . /src/mykonos-gcc
WORKDIR /src/mykonos-gcc
RUN ./contrib/download_prerequisites
WORKDIR /build
ARG ARCH=x86_64
RUN /src/mykonos-gcc/configure --target=${ARCH}-mykonos --disable-multilib --enable-languages=c,c++ --without-headers --prefix=/mykonos-gcc --enable-checking=release
RUN make all-gcc all-target-libgcc -j $(nproc)
RUN make install-strip-gcc install-strip-target-libgcc

FROM jett59/mykonos-binutils AS final
COPY --from=build /mykonos-gcc /mykonos-gcc
ENV PATH="/mykonos-gcc/bin:${PATH}"
