Import("env", "projenv")

# Generic
env.Replace(
    UPLOADER="./custom_uploader.sh",
    UPLOADCMD="$UPLOADER $SOURCE " + projenv["PIOENV"] + "$UPLOADERFLAGS"
)

