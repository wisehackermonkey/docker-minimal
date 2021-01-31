# FROM rust:1.42 as builder
# WORKDIR /usr/src

# # 1a: Prepare for static linking
# RUN apt-get update && \
#     apt-get dist-upgrade -y && \
#     apt-get install -y musl-tools && \
#     rustup target add x86_64-unknown-linux-musl

# # 1b: Download and compile Rust dependencies (and store as a separate Docker layer)
# RUN USER=root cargo new hello2
# WORKDIR /usr/src/hello2
# COPY Cargo.toml Cargo.lock ./
# RUN cargo install --target x86_64-unknown-linux-musl --path .

# # 1c: Build the exe using the actual source code
# COPY src ./src
# RUN cargo install --target x86_64-unknown-linux-musl --path .

# # 2: Copy the exe and extra files ("static") to an empty Docker image
# FROM scratch
# COPY --from=builder /usr/local/cargo/bin/hello2 .
# COPY static .
# USER 1000
# CMD ["./hello2"]
# # go docker file
# # FROM scratch
# # ADD /hello /
# # CMD ["/hello"]


FROM rust:1.35.0 AS build
WORKDIR /usr/src

# Download the target for static linking.
RUN rustup target add x86_64-unknown-linux-musl

# Create a dummy project and build the app's dependencies.
# If the Cargo.toml or Cargo.lock files have not changed,
# we can use the docker build cache and skip these (typically slow) steps.
RUN USER=root cargo new url-shortener
WORKDIR /usr/src/url-shortener
COPY Cargo.toml Cargo.lock ./
RUN cargo build --release

# Copy the source and build the application.
COPY ./src  ./src
RUN cargo install --target x86_64-unknown-linux-musl --path .

# Copy the statically-linked binary into a scratch container.
FROM scratch
COPY --from=build /usr/local/cargo/bin/url-shortener .
USER 1000
CMD ["./url-shortener"]