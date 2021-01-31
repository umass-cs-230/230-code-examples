#! /bin/env bash

# Zip weekly code
for fi in $(ls -d1 week-*); do
    zip -r zips/$fi $fi
done
