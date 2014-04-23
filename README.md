# Girlcoin [GIRL]
http://www.girlcoin.org/

## What is girlcoin?
Girlcoin is like Bitcoin, but based on Litecoin. http://www.girlcoin.org

## License
Girlcoin is released under the terms of the MIT license. See [COPYING](COPYING)
for more information or see http://opensource.org/licenses/MIT.

## Development and contributions
Developers work in their own trees, then submit pull requests when they think
their feature or bug fix is ready.

## Total GIRL coins

The total number of GIRL coins will be 10,000,000,000 GIRL coins.

## Block Time

30 Seconds

## Difficulty Retarget Time

1 hour

## Mining

You don’t need expensive mining equipment that uses lots of electricity. Just download your wallet and start mining using your computers CPU processing power.

## Rewards

Block 1-200,000 : 1-50,000 GIRL Reward
Block 200,001 -300,000 : 1-40,000 GIRL Reward
Block 300,001 -400,000 : 1-20,000 GIRL Reward
Block 400,001 -500,000 : 1-10,000 GIRL Reward
Block 500,001 -500,000 : 1-5,000 GIRL Reward
Block 600,001 -700,000 : 1-2,500 GIRL Reward
Block 700,001 -800,000 : 1-1,250 GIRL Reward
Block 800,001+ : 500 GIRL Reward

## Make girlcoind

    sudo apt-get install build-essential \
                         libssl-dev \
                         libdb5.1++-dev \
                         libboost-all-dev \
                         libqrencode-dev \
                         libminiupnpc-dev

    cd src/
    make -f makefile.unix USE_UPNP=1 USE_IPV6=1 USE_QRCODE=1

## Ports
RPC 33666
P2P 33667
