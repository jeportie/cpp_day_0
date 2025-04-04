#!/bin/bash

# Define colors for output
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

# Create test.log from account.log
make
./bin/account > assets/account.log
cat assets/account.log > assets/.test/logs/test.log

# Create base.log from 19920104_091532.log
 cat assets/19920104_091532.log > assets/.test/logs/base.log

 echo "Temporary files created: test.log and base.log"

# Remove timestamps from test.log
 sed -i 's/\[[0-9]\{8\}_[0-9]\{6\}\] //g' assets/.test/logs/test.log

# Remove timestamps from base.log
 sed -i 's/\[[0-9]\{8\}_[0-9]\{6\}\] //g' assets/.test/logs/base.log

# Compare the files
 diff_result=$(diff assets/.test/logs/test.log assets/.test/logs/base.log)

# Check if there are differences
 if [ -z "$diff_result" ]; then
     echo -e "${GREEN}✓ SUCCESS: The logs match after removing timestamps!${NC}"
 else
     echo -e "${RED}✗ FAILURE: The logs do not match after removing timestamps.${NC}"
     echo "Differences found:"
     echo "$diff_result"
 fi

# Clean up
make fclean
rm assets/.test/logs/base.log
rm assets/.test/logs/test.log
