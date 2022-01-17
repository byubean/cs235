# Build the CS 235 Lab Autograder Base
# Autograder base expects subsequent layers to add a file named run_tests.py 
#   that will generate /autograder/results/results.json

IMAGE_NAME="byubean/cs235-autograder-base"
IMAGE_TAG="latest"

docker buildx build \
    --platform linux/amd64,linux/arm64 \
    -t ${IMAGE_NAME}:${IMAGE_TAG} \
    --push \
    -f - . <<EOF

FROM gradescope/auto-builds:latest

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
      python-dev

RUN apt-get install -y \
      less \
      vim

RUN apt-get clean

RUN mkdir -p /autograder/results/

RUN echo "#!/bin/bash" > /autograder/run_autograder
RUN echo "cd /autograder/submission/ && python3 /autograder/run_tests.py && cp results.json /autograder/results/" >> /autograder/run_autograder

RUN chmod 755 /autograder/run_autograder

EOF

docker pull ${IMAGE_NAME}:${IMAGE_TAG}

