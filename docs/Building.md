# Building

Linux and Windows builds are handled automatically by the release pipeline (release.yml). To trigger the release build, simply tag the main branch with the version of the build. For example to build release 1.2.3, tag the branch with v1.2.3.

## From a Local Git Repo

```bash
> git checkout main
> git pull
> git tag -a vX.Y.Z -m "Version X.Y.Z"
> git push origin vX.Y.Z
```

This will push only the tag to main which is still permitted triggering a release build by the release pipeline.

# Versioning

Use three digit versions as follows.

**X.Y.Z**

**X** - Major Version. Increment when a major features is complete and released. For example swapping the entire database engine to a different piece.

**Y** - Minor Version. Increment when a new feature is complete and released. For example, changing the color of a button from blue to red. Not a major change, but still a change in features.

**Z** - Patch Version. Increment when a bug is fixed and release. For example, pressing a button was causing two events to fire and be processed.

NOTE: When any of the parent versions change, reset the child versions to zero. For example a minor release would cause 2.1.3 to become 2.2.0. Similarly a major release would cause 2.2.0 to become 3.0.0. This allows tracking of the "number" of changes made since the last major update.
