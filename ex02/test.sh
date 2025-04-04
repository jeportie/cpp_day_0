#!/bin/bash

# Define colors for output
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

# Function to display a loading bar
show_loading() {
    echo -n "Processing"
    for i in {1..10}; do
        echo -n "."
        sleep 0.1
    done
    echo ""
}

# Create test.log from account.log
make > /dev/null 2>&1
./bin/account > assets/account.log 2>&1
cat assets/account.log > assets/.test/logs/test.log 2>&1

# Create base.log from 19920104_091532.log
cat assets/19920104_091532.log > assets/.test/logs/base.log 2>&1

# Remove timestamps from test.log
sed -i 's/\[[0-9]\{8\}_[0-9]\{6\}\] //g' assets/.test/logs/test.log 2>&1

# Remove timestamps from base.log
sed -i 's/\[[0-9]\{8\}_[0-9]\{6\}\] //g' assets/.test/logs/base.log 2>&1

# Show loading bar
show_loading

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
make fclean > /dev/null 2>&1
rm assets/.test/logs/base.log > /dev/null 2>&1
rm assets/.test/logs/test.log > /dev/null 2>&1
