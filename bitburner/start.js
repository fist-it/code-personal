/** @param {NS} ns */
export async function main(ns) {
    while (true) {
      await ns.hack('n00dles');
      await ns.hack('foodnstuff');
      if(getHackingLevel() > 100) {
        break;
      }
    }
  }