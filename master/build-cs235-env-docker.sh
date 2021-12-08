# Build and push the cs235-env docker image

IMAGE_NAME="byubean/cs235-env"
IMAGE_TAG="latest"

docker buildx build \
    --platform linux/amd64,linux/arm64 \
    -t ${IMAGE_NAME}:${IMAGE_TAG} \
    --push \
    -f - . <<EOF

FROM ubuntu:20.04

# Must install tzdata in "noninteractive" mode to avoid blocking the build 
RUN DEBIAN_FRONTEND="noninteractive" apt-get update && apt-get -y install tzdata

RUN apt-get update \
  && apt-get install -y build-essential \
      gcc \
      g++ \
      gdb \
      clang \
      make \
      valgrind \
      ninja-build \
      cmake \
      autoconf \
      automake \
      locales-all \
      dos2unix \
      rsync \
      tar \
      python \
      python-dev \
  && apt-get clean

EOF

docker pull ${IMAGE_NAME}:${IMAGE_TAG}
