# Build the CS 235 Lab 2 Autograder

IMAGE_NAME="byubean/cs235-lab2-autograder"
IMAGE_TAG="latest"

docker buildx build \
    --platform linux/amd64,linux/arm64 \
    -t ${IMAGE_NAME}:${IMAGE_TAG} \
    --push \
    -f - . <<EOF

FROM byubean/cs235-autograder-base

ADD run_lab2_tests.py /autograder/run_tests.py

EOF

docker pull ${IMAGE_NAME}:${IMAGE_TAG}

