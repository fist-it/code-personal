/** @param {NS} ns */
var target = arg[0];
var moneyThresh = getServerMaxMoney(target) * 0.9;
var securityThresh = getServerMinSecurityLevel(target) + 5;
if (fileExists("BruteSSH.exe", "home")) {
    brutessh(target);
    tprint("BruteSSH.exe installed");
}

if (fileExists("FTPCrack.exe", "home")) {
    ftpcrack(target);
    tprint("FTPCrack.exe installed");
}

if (fileExists("relaySMTP.exe", "home")) {
    relaysmtp(target);
    tprint("relaySMTP.exe installed");
}

if (fileExists("HTTPWorm.exe", "home")) {
    httpworm(target);
    tprint("HTTPWorm.exe installed");
}

if (fileExists("SQLInject.exe", "home")) {
    sqlinject(target);
    tprint("SQLInject.exe installed");
}

nuke(target);
while(true) {
  if (getServerSecurityLevel(target) > securityThresh) {
    weaken(target);
  } else if (getServerMoneyAvailable(target) < moneyThresh) {
    grow(target);
  } else {
    hack(target);
  }
}