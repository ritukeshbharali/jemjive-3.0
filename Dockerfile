FROM ubuntu:22.04

# Install dependencies
RUN apt-get update && apt-get install -y \
    build-essential g++ \
    zlib1g-dev \
    libreadline-dev \
    freeglut3-dev \
    openmpi-bin openmpi-common libopenmpi-dev \
    git

# Set workspace
WORKDIR /opt

# Copy sources
COPY jem-3.0 /opt/jem-3.0
COPY jive-3.0 /opt/jive-3.0

# Build JEM
WORKDIR /opt/jem-3.0
RUN ./configure --cxx=mpic++ && make -j$(nproc)

# Build JIVE (requires JEMDIR)
ENV JEMDIR=/opt/jem-3.0
WORKDIR /opt/jive-3.0
RUN ./configure && make -j$(nproc)

# Export paths so Falcon can use them
ENV JEMDIR=/opt/jem-3.0
ENV JIVEDIR=/opt/jive-3.0

WORKDIR /workspace
