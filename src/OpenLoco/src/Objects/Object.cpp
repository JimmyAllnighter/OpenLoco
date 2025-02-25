#include "Object.h"
#include <string_view>
#include <tuple>
#include <unordered_set>

namespace OpenLoco
{
    // Original headers are unique for name and type only
    using VanillaHeader = std::tuple<std::string_view, ObjectType>;

    struct VanillaHeaderHash
    {
        template<class T>
        static inline void hashCombine(std::size_t& seed, const T& v)
        {
            std::hash<T> hasher;
            seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2); // Based on boost::hash_combine
        }

        std::size_t operator()(VanillaHeader const& header) const noexcept
        {
            std::size_t h = 0U;
            hashCombine(h, std::get<0>(header));
            hashCombine(h, std::get<1>(header));
            return h;
        }
    };

    static const std::unordered_set<VanillaHeader, VanillaHeaderHash> _vanillaObjects = {
        // Type 0 (interfaceSkin)
        { "INTERDEF", ObjectType::interfaceSkin }, // "Default Interface Style"

        // Type 1 (sound)
        { "SNDA1   ", ObjectType::sound }, // "Aircraft sound 1"
        { "SNDA2   ", ObjectType::sound }, // "Aircraft sound 2"
        { "SNDA3   ", ObjectType::sound }, // "Aircraft sound 3"
        { "SNDTD1  ", ObjectType::sound }, // "Aircraft touchdown sound 1"
        { "SNDTD2  ", ObjectType::sound }, // "Aircraft touchdown sound 2"
        { "SNDH4   ", ObjectType::sound }, // "Boat Horn sound 4"
        { "SNDH5   ", ObjectType::sound }, // "Boat Horn sound 5"
        { "SNDH6   ", ObjectType::sound }, // "Boat Horn sound 6"
        { "SNDCH1A ", ObjectType::sound }, // "Chuff 1 (a)"
        { "SNDCH1AS", ObjectType::sound }, // "Chuff 1 (a-st)"
        { "SNDCH1B ", ObjectType::sound }, // "Chuff 1 (b)"
        { "SNDCH1BS", ObjectType::sound }, // "Chuff 1 (b-st)"
        { "SNDCH1C ", ObjectType::sound }, // "Chuff 1 (c)"
        { "SNDCH1CS", ObjectType::sound }, // "Chuff 1 (c-st)"
        { "SNDCH1D ", ObjectType::sound }, // "Chuff 1 (d)"
        { "SNDCH1DS", ObjectType::sound }, // "Chuff 1 (d-st)"
        { "SNDD1   ", ObjectType::sound }, // "Diesel sound 1"
        { "SNDD10  ", ObjectType::sound }, // "Diesel sound 10"
        { "SNDD11  ", ObjectType::sound }, // "Diesel sound 11"
        { "SNDD12  ", ObjectType::sound }, // "Diesel sound 12"
        { "SNDD2   ", ObjectType::sound }, // "Diesel sound 2"
        { "SNDD3   ", ObjectType::sound }, // "Diesel sound 3"
        { "SNDD4   ", ObjectType::sound }, // "Diesel sound 4"
        { "SNDD5   ", ObjectType::sound }, // "Diesel sound 5"
        { "SNDD6   ", ObjectType::sound }, // "Diesel sound 6"
        { "SNDD7   ", ObjectType::sound }, // "Diesel sound 7"
        { "SNDD8   ", ObjectType::sound }, // "Diesel sound 8"
        { "SNDD9   ", ObjectType::sound }, // "Diesel sound 9"
        { "SNDE1   ", ObjectType::sound }, // "Electric sound 1"
        { "SNDH1   ", ObjectType::sound }, // "Loco horn sound 1"
        { "SNDH2   ", ObjectType::sound }, // "Loco horn sound 2"
        { "SNDH3   ", ObjectType::sound }, // "Loco horn sound 3"
        { "SNDW1   ", ObjectType::sound }, // "Loco whistle sound 1"
        { "SNDW2   ", ObjectType::sound }, // "Loco whistle sound 2"
        { "SNDW3   ", ObjectType::sound }, // "Loco whistle sound 3"
        { "SNDW4   ", ObjectType::sound }, // "Loco whistle sound 4"
        { "SNDW5   ", ObjectType::sound }, // "Loco whistle sound 5"
        { "SNDW6   ", ObjectType::sound }, // "Loco whistle sound 6"
        { "SNDW7   ", ObjectType::sound }, // "Loco whistle sound 7"
        { "SNDW8   ", ObjectType::sound }, // "Loco whistle sound 8"
        { "SNDS1   ", ObjectType::sound }, // "Steam idle sound 1"
        { "SNDTR1  ", ObjectType::sound }, // "Track sound 1"

        // Type 2 (currency)
        { "CURRDMRK", ObjectType::currency }, // "Deutschmark"
        { "CURRDOLL", ObjectType::currency }, // "Dollars"
        { "CURREURO", ObjectType::currency }, // "Euros"
        { "CURRFREN", ObjectType::currency }, // "Franc"
        { "CURRGUIL", ObjectType::currency }, // "Guilders"
        { "CURRKRON", ObjectType::currency }, // "Krona"
        { "CURRLIRA", ObjectType::currency }, // "Lira"
        { "CURRPSTA", ObjectType::currency }, // "Peseta"
        { "CURRPNDS", ObjectType::currency }, // "Pounds"
        { "CURRNTDL", ObjectType::currency }, // "Taiwanese Dollars"
        { "CURRWON ", ObjectType::currency }, // "Won"
        { "CURRYEN ", ObjectType::currency }, // "Yen"
        { "CURRZLOT", ObjectType::currency }, // "Zlote"

        // Type 3 (steam)
        { "EXH1    ", ObjectType::steam }, // "Diesel Exhaust"
        { "EXH2    ", ObjectType::steam }, // "Diesel Exhaust"
        { "SPARK1  ", ObjectType::steam }, // "Electric Spark"
        { "WWAKE1  ", ObjectType::steam }, // "Ship Wake 1"
        { "STEAM   ", ObjectType::steam }, // "Steam Puff"

        // Type 4 (cliffEdge)
        { "LSBROWN ", ObjectType::cliffEdge }, // "Brown Rock"
        { "LSROCK  ", ObjectType::cliffEdge }, // "Rock"

        // Type 5 (water)
        { "WATER1  ", ObjectType::water }, // "Water"

        // Type 6 (land)
        { "ROCK2   ", ObjectType::land }, // "Brown Rock"
        { "GRASSBR ", ObjectType::land }, // "Dry Grass"
        { "GRASS1  ", ObjectType::land }, // "Grass"
        { "ROCK1   ", ObjectType::land }, // "Grey Rock"
        { "SAND1   ", ObjectType::land }, // "Sand"

        // Type 7 (townNames)
        { "ETOWNNAM", ObjectType::townNames }, // "English style town names"
        { "FTOWNNAM", ObjectType::townNames }, // "French style town names"
        { "GTOWNNAM", ObjectType::townNames }, // "German style town names"
        { "LTOWNNAM", ObjectType::townNames }, // "Latin style town names"
        { "ATOWNNAM", ObjectType::townNames }, // "North-American style town names"
        { "STOWNNAM", ObjectType::townNames }, // "Silly style town names"

        // Type 8 (cargo)
        { "CHEMICAL", ObjectType::cargo }, // "Chemicals"
        { "COAL    ", ObjectType::cargo }, // "Coal"
        { "FOOD    ", ObjectType::cargo }, // "Food"
        { "GOODS   ", ObjectType::cargo }, // "Goods"
        { "GRAIN   ", ObjectType::cargo }, // "Grain"
        { "GRAPES  ", ObjectType::cargo }, // "Grapes"
        { "IRONORE ", ObjectType::cargo }, // "Iron Ore"
        { "LIVESTCK", ObjectType::cargo }, // "Livestock"
        { "TIMBER  ", ObjectType::cargo }, // "Lumber"
        { "MAIL    ", ObjectType::cargo }, // "Mail"
        { "OIL     ", ObjectType::cargo }, // "Oil"
        { "PAPER   ", ObjectType::cargo }, // "Paper"
        { "PASS    ", ObjectType::cargo }, // "Passengers"
        { "STEEL   ", ObjectType::cargo }, // "Steel"

        // Type 9 (wall)
        { "FENCE1  ", ObjectType::wall }, // "Fence"
        { "FENCE1G ", ObjectType::wall }, // "Fence"
        { "SECFENCE", ObjectType::wall }, // "Security Fence"
        { "SECFENCG", ObjectType::wall }, // "Security Fence"
        { "STONWALG", ObjectType::wall }, // "Stone Wall"
        { "STONWALL", ObjectType::wall }, // "Stone Wall"
        { "BRWNWALG", ObjectType::wall }, // "Wall"
        { "BRWNWALL", ObjectType::wall }, // "Wall"

        // Type 10 (trackSignal)
        { "SIGC3   ", ObjectType::trackSignal }, // "Colourlight"
        { "SIGCSW  ", ObjectType::trackSignal }, // "Colourlight"
        { "SIGCUS  ", ObjectType::trackSignal }, // "Colourlight"
        { "SIGC4   ", ObjectType::trackSignal }, // "Colourlight (4-aspect)"
        { "SIGSUS  ", ObjectType::trackSignal }, // "Semaphore"
        { "SIGSW   ", ObjectType::trackSignal }, // "Semaphore"
        { "SIGSL   ", ObjectType::trackSignal }, // "Semaphore (LQ)"
        { "SIGSDL  ", ObjectType::trackSignal }, // "Semaphore (LQD)"
        { "SIGS    ", ObjectType::trackSignal }, // "Semaphore (UQ)"
        { "SIGSD   ", ObjectType::trackSignal }, // "Semaphore (UQD)"

        // Type 11 (levelCrossing)
        { "LCROSS3 ", ObjectType::levelCrossing }, // "Level Crossing Gates"
        { "LCROSS1 ", ObjectType::levelCrossing }, // "Level Crossing Lights"
        { "LCROSS2 ", ObjectType::levelCrossing }, // "Level Crossing Lights"
        { "LCROSS4 ", ObjectType::levelCrossing }, // "Level Crossing Signs"

        // Type 12 (streetLight)
        { "SLIGHT1 ", ObjectType::streetLight }, // "Street Lights"

        // Type 13 (tunnel)
        { "TUNNEL1 ", ObjectType::tunnel }, // "Tunnel"
        { "TUNNEL2 ", ObjectType::tunnel }, // "Tunnel"

        // Type 14 (bridge)
        { "BRDGBRCK", ObjectType::bridge }, // "Brick Bridge"
        { "BRDGSTAR", ObjectType::bridge }, // "Steel Arch Bridge"
        { "BRDGGIRD", ObjectType::bridge }, // "Steel Girder Bridge"
        { "BRDGSUSP", ObjectType::bridge }, // "Suspension Bridge"
        { "BRDGWOOD", ObjectType::bridge }, // "Wooden Bridge"

        // Type 15 (trackStation)
        { "TRSTAT1 ", ObjectType::trackStation }, // "City Station"
        { "TRSTAT4 ", ObjectType::trackStation }, // "City Station"
        { "TRSTAT5 ", ObjectType::trackStation }, // "Station"
        { "TRSTAT2 ", ObjectType::trackStation }, // "Station"
        { "TRSTAT3 ", ObjectType::trackStation }, // "Station"

        // Type 16 (trackExtra)
        { "TREX3RL ", ObjectType::trackExtra }, // "Electric 3rd Rail"
        { "TREXCAT1", ObjectType::trackExtra }, // "Overhead Elec. Wires"
        { "TREXRACK", ObjectType::trackExtra }, // "Rack Rail"

        // Type 17 (track)
        { "TRACKNG ", ObjectType::track }, // "Narrow Gauge Track"
        { "TRACKST ", ObjectType::track }, // "Railway Track"

        // Type 18 (roadStation)
        { "RDSTATL1", ObjectType::roadStation }, // "Cargo Loading Bay"
        { "RDSTATL2", ObjectType::roadStation }, // "Cargo Loading Bay"
        { "RDSTATL3", ObjectType::roadStation }, // "Cargo Loading Bay"
        { "BUSSTOP ", ObjectType::roadStation }, // "Passenger Stop"
        { "RDSTAT1 ", ObjectType::roadStation }, // "Passenger Terminus"
        { "RDSTAT2 ", ObjectType::roadStation }, // "Passenger Terminus"
        { "RDSTAT3 ", ObjectType::roadStation }, // "Passenger Terminus"

        // Type 19 (roadExtra)
        { "RDEXCAT1", ObjectType::roadExtra }, // "Overhead Elec. Wires"

        // Type 20 (road)
        { "ROADONE ", ObjectType::road }, // "One-Way Road"
        { "ROADUS1 ", ObjectType::road }, // "One-Way Road"
        { "ROADTMC ", ObjectType::road }, // "Road"
        { "ROADUS2 ", ObjectType::road }, // "Road"
        { "ROADRGH ", ObjectType::road }, // "Rough Road"
        { "ROADTRAM", ObjectType::road }, // "Tram Track"

        // Type 21 (airport)
        { "HPORT1  ", ObjectType::airport }, // "City Heliport"
        { "AIRPORT4", ObjectType::airport }, // "International Airport"
        { "AIRPORT1", ObjectType::airport }, // "Large Airport"
        { "HPORT2  ", ObjectType::airport }, // "Large Heliport"
        { "AIRPORT3", ObjectType::airport }, // "Medium Airport"
        { "AIRPORT2", ObjectType::airport }, // "Small Airport"

        // Type 22 (dock)
        { "SHIPST1 ", ObjectType::dock }, // "Docks"

        // Type 23 (vehicle)
        { "2EPB    ", ObjectType::vehicle }, // "2-EPB Electric Multiple Unit"
        { "JINTY   ", ObjectType::vehicle }, // "3F 'Jinty'"
        { "707     ", ObjectType::vehicle }, // "707"
        { "737     ", ObjectType::vehicle }, // "737"
        { "747     ", ObjectType::vehicle }, // "747"
        { "777     ", ObjectType::vehicle }, // "777"
        { "A320    ", ObjectType::vehicle }, // "A320"
        { "A380    ", ObjectType::vehicle }, // "A380"
        { "A5      ", ObjectType::vehicle }, // "A5 Tri-Motor"
        { "AB139   ", ObjectType::vehicle }, // "AB139 Helicopter"
        { "APT1    ", ObjectType::vehicle }, // "APT Driving Carriage"
        { "APT2    ", ObjectType::vehicle }, // "APT Passenger Carriage"
        { "APT3    ", ObjectType::vehicle }, // "APT Power Car"
        { "AE47    ", ObjectType::vehicle }, // "Ae 4/7"
        { "AILSA1  ", ObjectType::vehicle }, // "Ailsa Bus"
        { "BA146   ", ObjectType::vehicle }, // "BAe 146"
        { "4MT     ", ObjectType::vehicle }, // "BR Standard Class 4MT"
        { "BALDWIN1", ObjectType::vehicle }, // "Baldwin 2-8-0"
        { "TRAM1   ", ObjectType::vehicle }, // "Be 4/4 Tram"
        { "TRAM4   ", ObjectType::vehicle }, // "Be 4/6 Tram"
        { "GOODS2  ", ObjectType::vehicle }, // "Boxcar"
        { "GOODS3  ", ObjectType::vehicle }, // "Boxcar"
        { "COALSH  ", ObjectType::vehicle }, // "Bulk Ship"
        { "C130    ", ObjectType::vehicle }, // "C-130 Hercules"
        { "CARGOSH1", ObjectType::vehicle }, // "Cargo Ship"
        { "CTRUCK1 ", ObjectType::vehicle }, // "Cattle Truck"
        { "CTRUCK2 ", ObjectType::vehicle }, // "Cattle Truck"
        { "CTRUCK3 ", ObjectType::vehicle }, // "Cattle Truck"
        { "CTRUCK4 ", ObjectType::vehicle }, // "Cattle Truck"
        { "TRAM2   ", ObjectType::vehicle }, // "Ce 2/2 Tram"
        { "CE68    ", ObjectType::vehicle }, // "Ce 6/8 Crocodile"
        { "ALCOCENT", ObjectType::vehicle }, // "Century"
        { "114     ", ObjectType::vehicle }, // "Class 114 Diesel Multiple Unit"
        { "142     ", ObjectType::vehicle }, // "Class 142 Diesel Railbus"
        { "158     ", ObjectType::vehicle }, // "Class 158 Diesel Multiple Unit"
        { "CL20    ", ObjectType::vehicle }, // "Class 20"
        { "CL37    ", ObjectType::vehicle }, // "Class 37"
        { "CL47    ", ObjectType::vehicle }, // "Class 47"
        { "508     ", ObjectType::vehicle }, // "Class 508 Electric Multiple Unit"
        { "CL55    ", ObjectType::vehicle }, // "Class 55 'Deltic'"
        { "CL58    ", ObjectType::vehicle }, // "Class 58"
        { "656     ", ObjectType::vehicle }, // "Class 656"
        { "CL67    ", ObjectType::vehicle }, // "Class 67"
        { "CL71    ", ObjectType::vehicle }, // "Class 71"
        { "CL85    ", ObjectType::vehicle }, // "Class 85"
        { "CL86    ", ObjectType::vehicle }, // "Class 86"
        { "CL90    ", ObjectType::vehicle }, // "Class 90"
        { "E8      ", ObjectType::vehicle }, // "Class E8"
        { "CLIPPER ", ObjectType::vehicle }, // "Clipper"
        { "TRAMCOMB", ObjectType::vehicle }, // "Combi Tram"
        { "COMET   ", ObjectType::vehicle }, // "Comet"
        { "CONCOR  ", ObjectType::vehicle }, // "Concorde"
        { "TRAM3   ", ObjectType::vehicle }, // "Coronation Tram"
        { "GRAINHP2", ObjectType::vehicle }, // "Covered Hopper Wagon"
        { "GRAINHP1", ObjectType::vehicle }, // "Covered Hopper Wagon"
        { "DC3     ", ObjectType::vehicle }, // "DC-3"
        { "DH16    ", ObjectType::vehicle }, // "DH-16"
        { "DASH7   ", ObjectType::vehicle }, // "Dash-7"
        { "DEH46   ", ObjectType::vehicle }, // "Deh 4/6"
        { "FERRY1  ", ObjectType::vehicle }, // "Diesel Ferry"
        { "EWIVDT  ", ObjectType::vehicle }, // "EW-IV Driving Carriage"
        { "EWIV    ", ObjectType::vehicle }, // "EW-IV Passenger Carriage"
        { "EB35    ", ObjectType::vehicle }, // "Eb 3/5"
        { "ESTAR2  ", ObjectType::vehicle }, // "Electra-Star Passenger Carriage"
        { "ESTAR1  ", ObjectType::vehicle }, // "Electra-Star Power Car"
        { "EMU1    ", ObjectType::vehicle }, // "Electric Multiple Unit"
        { "F27     ", ObjectType::vehicle }, // "F.27"
        { "F7      ", ObjectType::vehicle }, // "F.7"
        { "FTRUCK1 ", ObjectType::vehicle }, // "Flatbed Truck"
        { "FTRUCK2 ", ObjectType::vehicle }, // "Flatbed Truck"
        { "FTRUCK3 ", ObjectType::vehicle }, // "Flatbed Truck"
        { "FTRUCK4 ", ObjectType::vehicle }, // "Flatbed Truck"
        { "FLATBED1", ObjectType::vehicle }, // "Flatbed Wagon"
        { "FLATBED2", ObjectType::vehicle }, // "Flatbed Wagon"
        { "FLTBEDN1", ObjectType::vehicle }, // "Flatbed Wagon"
        { "4F      ", ObjectType::vehicle }, // "Fowler 4F"
        { "CLASSIC ", ObjectType::vehicle }, // "GM Classic"
        { "GE442   ", ObjectType::vehicle }, // "Ge 4/4 II"
        { "GE443   ", ObjectType::vehicle }, // "Ge 4/4 III"
        { "GE66    ", ObjectType::vehicle }, // "Ge 6/6"
        { "GTRUCK1 ", ObjectType::vehicle }, // "Goods Truck"
        { "GTRUCK2 ", ObjectType::vehicle }, // "Goods Truck"
        { "GTRUCK3 ", ObjectType::vehicle }, // "Goods Truck"
        { "GTRUCK4 ", ObjectType::vehicle }, // "Goods Truck"
        { "PVAN2   ", ObjectType::vehicle }, // "Goods Van"
        { "GOODS1  ", ObjectType::vehicle }, // "Goods Wagon"
        { "GOODSN1 ", ObjectType::vehicle }, // "Goods Wagon"
        { "A3      ", ObjectType::vehicle }, // "Gresley A3"
        { "A4      ", ObjectType::vehicle }, // "Gresley A4"
        { "V2      ", ObjectType::vehicle }, // "Gresley V2"
        { "HGE44   ", ObjectType::vehicle }, // "HGe 4/4"
        { "HGE442  ", ObjectType::vehicle }, // "HGe 4/4 II"
        { "HST     ", ObjectType::vehicle }, // "HST Power Car"
        { "HTRUCK1 ", ObjectType::vehicle }, // "Hopper Truck"
        { "HTRUCK2 ", ObjectType::vehicle }, // "Hopper Truck"
        { "HTRUCK3 ", ObjectType::vehicle }, // "Hopper Truck"
        { "HTRUCK4 ", ObjectType::vehicle }, // "Hopper Truck"
        { "HOPPER  ", ObjectType::vehicle }, // "Hopper Wagon"
        { "HOPPER2 ", ObjectType::vehicle }, // "Hopper Wagon"
        { "HFOIL1  ", ObjectType::vehicle }, // "Hydrofoil"
        { "JU52    ", ObjectType::vehicle }, // "JU52"
        { "JFOIL1  ", ObjectType::vehicle }, // "Jetfoil"
        { "LEOP1   ", ObjectType::vehicle }, // "Leopard Bus"
        { "CATTLEN1", ObjectType::vehicle }, // "Livestock Wagon"
        { "CATTLE1 ", ObjectType::vehicle }, // "Livestock Wagon"
        { "CATTLE3 ", ObjectType::vehicle }, // "Livestock Wagon"
        { "MAILUS1 ", ObjectType::vehicle }, // "Mail Car"
        { "MAILUS2 ", ObjectType::vehicle }, // "Mail Car"
        { "MTRUCK1 ", ObjectType::vehicle }, // "Mail Truck"
        { "MTRUCK2 ", ObjectType::vehicle }, // "Mail Truck"
        { "MTRUCK3 ", ObjectType::vehicle }, // "Mail Truck"
        { "CARGOSH2", ObjectType::vehicle }, // "Merchant Freighter"
        { "MK1     ", ObjectType::vehicle }, // "Mk1 Passenger Carriage"
        { "MK2     ", ObjectType::vehicle }, // "Mk2 Passenger Carriage"
        { "MK3     ", ObjectType::vehicle }, // "Mk3 Passenger Carriage"
        { "36R     ", ObjectType::vehicle }, // "Model 36R Bus"
        { "OILSH   ", ObjectType::vehicle }, // "Oil Tanker"
        { "USPACIF ", ObjectType::vehicle }, // "Pacific"
        { "PVAN1   ", ObjectType::vehicle }, // "Parcel Van"
        { "SWISS5  ", ObjectType::vehicle }, // "Passenger Carriage"
        { "PCAR1   ", ObjectType::vehicle }, // "Passenger Carriage"
        { "PCAR2   ", ObjectType::vehicle }, // "Passenger Carriage"
        { "PCARSW1 ", ObjectType::vehicle }, // "Passenger Carriage"
        { "PCARUS1 ", ObjectType::vehicle }, //  "Passenger Carriage"
        { "PCARUS2 ", ObjectType::vehicle }, // "Passenger Carriage"
        { "SWISS1  ", ObjectType::vehicle }, // "Passenger Carriage"
        { "SWISS2  ", ObjectType::vehicle }, // "Passenger Carriage"
        { "SWISS3  ", ObjectType::vehicle }, // "Passenger Carriage"
        { "SWISS4  ", ObjectType::vehicle }, // "Passenger Carriage"
        { "MAILSW1 ", ObjectType::vehicle }, // "Postal Van"
        { "MAILSW4 ", ObjectType::vehicle }, // "Postal Van"
        { "RBE24   ", ObjectType::vehicle }, // "RBe 2/4 Railcar"
        { "RTMASTER", ObjectType::vehicle }, // "RMT Bus"
        { "RE441   ", ObjectType::vehicle }, // "Re 4/4 I"
        { "RE442   ", ObjectType::vehicle }, // "Re 4/4 II"
        { "460     ", ObjectType::vehicle }, // "Re 460"
        { "COPTER1 ", ObjectType::vehicle }, // "S55 Helicopter"
        { "SD70MAC ", ObjectType::vehicle }, // "SD70"
        { "C33     ", ObjectType::vehicle }, // "SLM C 3/3"
        { "C56     ", ObjectType::vehicle }, // "SLM C 5/6"
        { "HG23    ", ObjectType::vehicle }, // "SLM HG 2/3"
        { "HCRAFT1 ", ObjectType::vehicle }, // "SRN4 Hovercraft"
        { "SHINKT0 ", ObjectType::vehicle }, // "Shinkansen Series 0 Powered Carriage"
        { "SHINKF0 ", ObjectType::vehicle }, // "Shinkansen Series 0 Powered Driving Carriage"
        { "SPECIAL ", ObjectType::vehicle }, // "Special 2-4-2"
        { "BLACK5  ", ObjectType::vehicle }, // "Stanier Black 5"
        { "STANCORR", ObjectType::vehicle }, // "Stanier Coronation Pacific"
        { "JUBILEE ", ObjectType::vehicle }, // "Stanier Jubilee"
        { "FERRY2  ", ObjectType::vehicle }, // "Steam Ferry"
        { "ST8FT   ", ObjectType::vehicle }, // "Stirling 8ft"
        { "CATTLE2 ", ObjectType::vehicle }, // "Stockcar"
        { "TDH5301 ", ObjectType::vehicle }, // "TDH 5301 Bus"
        { "TGV2    ", ObjectType::vehicle }, // "TGV Passenger Carriage"
        { "TGV1    ", ObjectType::vehicle }, // "TGV Power Car"
        { "TTRAIL2 ", ObjectType::vehicle }, // "Tanker Trailer"
        { "TTRUCK1 ", ObjectType::vehicle }, // "Tanker Truck"
        { "TTRUCK2 ", ObjectType::vehicle }, // "Tanker Truck"
        { "TTRUCK3 ", ObjectType::vehicle }, // "Tanker Truck"
        { "TTRUCK4 ", ObjectType::vehicle }, // "Tanker Truck"
        { "OIL1    ", ObjectType::vehicle }, // "Tanker Wagon"
        { "OIL2    ", ObjectType::vehicle }, // "Tanker Wagon"
        { "OILN1   ", ObjectType::vehicle }, // "Tanker Wagon"
        { "VISCOUNT", ObjectType::vehicle }, // "Viscount"
        { "VULCAN  ", ObjectType::vehicle }, // "Vulcan VSD Bus"
        { "WMCBUS  ", ObjectType::vehicle }, // "WMC Bus"
        { "COAL1   ", ObjectType::vehicle }, // "Wagon"
        { "OPENN1  ", ObjectType::vehicle }, // "Wagon"

        // Type 24 (tree)
        { "BSPRUCE ", ObjectType::tree }, // "Blue Spruce Tree"
        { "CACTUS1 ", ObjectType::tree }, // "Cactus"
        { "CACTUS2 ", ObjectType::tree }, // "Cactus"
        { "CACTUS3 ", ObjectType::tree }, // "Cactus"
        { "LCEDAR  ", ObjectType::tree }, // "Cedar of Lebanon Tree"
        { "CHESTNUT", ObjectType::tree }, // "Chestnut Tree"
        { "BEECH   ", ObjectType::tree }, // "Common Beech Tree"
        { "COPBEACH", ObjectType::tree }, // "Copper Beach Tree"
        { "WILLOW  ", ObjectType::tree }, // "Crack Willow Tree"
        { "DREDWOOD", ObjectType::tree }, // "Dawn Redwood Tree"
        { "ELM     ", ObjectType::tree }, // "Elm Tree"
        { "FRISIA  ", ObjectType::tree }, // "Frisia Tree"
        { "HCYPRESS", ObjectType::tree }, // "Golden Hinoki Cypress Tree"
        { "GFIR    ", ObjectType::tree }, // "Grand Fir Tree"
        { "HSTRAW  ", ObjectType::tree }, // "Hydrid Strawberry Tree"
        { "IYEW    ", ObjectType::tree }, // "Irish Yew Tree"
        { "ICYPRESS", ObjectType::tree }, // "Italian Cypress Tree"
        { "JAPCRAB ", ObjectType::tree }, // "Japanese Crab Tree"
        { "JOSHUA  ", ObjectType::tree }, // "Joshua Tree"
        { "KBFIR   ", ObjectType::tree }, // "King Boris's Fir Tree"
        { "NMAPLE  ", ObjectType::tree }, // "Maple Tree"
        { "NASH    ", ObjectType::tree }, // "Narrow Leaf Ash Tree"
        { "OAK     ", ObjectType::tree }, // "Oak Tree"
        { "PCYPRESS", ObjectType::tree }, // "Pond Cypress Tree"
        { "QPALM   ", ObjectType::tree }, // "Queen Palm Tree"
        { "RCEDAR  ", ObjectType::tree }, // "Red Cedar Tree"
        { "RFIR    ", ObjectType::tree }, // "Red Fir Tree"
        { "ROBINIA ", ObjectType::tree }, // "Robinia Tree"
        { "SCPINE  ", ObjectType::tree }, // "Scots Pine Tree"
        { "BIRCH   ", ObjectType::tree }, // "Silver Birch Tree"
        { "BIRCH2  ", ObjectType::tree }, // "Silver Birch Tree"
        { "SPALM   ", ObjectType::tree }, // "Silver Palm Tree"
        { "SVPINE  ", ObjectType::tree }, // "Silver Pine Tree"
        { "SNOWBELL", ObjectType::tree }, // "Snowbell Tree"
        { "SMAPLE  ", ObjectType::tree }, // "Sugar Maple Tree"
        { "SCYPRESS", ObjectType::tree }, // "Swamp Cypress Tree"
        { "WASH    ", ObjectType::tree }, // "White Ash Tree"
        { "YEW     ", ObjectType::tree }, // "Yew Tree"
        { "YUKKA   ", ObjectType::tree }, // "Yukka Plant"

        // Type 25 (snow)
        { "SNOW    ", ObjectType::snow }, // "Snow"

        // Type 26 (climate)
        { "CLIM1   ", ObjectType::climate }, // "Alpine Climate"
        { "CLIM4   ", ObjectType::climate }, // "Australian Climate"
        { "CLIM2   ", ObjectType::climate }, // "British Climate"
        { "CLIM5   ", ObjectType::climate }, // "Low Alpine Climate"
        { "CLIM3   ", ObjectType::climate }, // "North American Climate"
        { "CLIM6   ", ObjectType::climate }, // "North American, No Snow"

        // Type 27 (hillShapes)
        { "HS1     ", ObjectType::hillShapes }, // "Hill Shapes 1"

        // Type 28 (building)
        { "BLDALP8 ", ObjectType::building }, // "Apartments"
        { "BLDALP1 ", ObjectType::building }, // "Building"
        { "BLDHOU14", ObjectType::building }, // "Bungalow"
        { "BLDHOU18", ObjectType::building }, // "Bungalow"
        { "BLDCASTL", ObjectType::building }, // "Castle Ruins"
        { "BLDCRCH1", ObjectType::building }, // "Church"
        { "BLDCRCH2", ObjectType::building }, // "Church"
        { "BLDCRCH3", ObjectType::building }, // "Church"
        { "HQ1     ", ObjectType::building }, // "Company Headquarters"
        { "BLDHALL1", ObjectType::building }, // "Concert Hall"
        { "BLDALP3 ", ObjectType::building }, // "Cottage"
        { "BLDHOU10", ObjectType::building }, // "Cottage"
        { "BLDHOU20", ObjectType::building }, // "Cottage"
        { "BLDHOUS4", ObjectType::building }, // "Cottage"
        { "BLDHOUS6", ObjectType::building }, // "Cottage"
        { "BLDHOUS7", ObjectType::building }, // "Cottage"
        { "BLDHOUS9", ObjectType::building }, // "Cottage"
        { "BLDALP2 ", ObjectType::building }, // "Cottage"
        { "BLDHOUS8", ObjectType::building }, // "Cottages"
        { "BLDCTY21", ObjectType::building }, // "Court House"
        { "BLDPYLON", ObjectType::building }, // "Electricity Pylon"
        { "BLDCTY17", ObjectType::building }, // "Flats"
        { "BLDCTY20", ObjectType::building }, // "Flats"
        { "BLDFOUNT", ObjectType::building }, // "Fountain"
        { "BLDCTY18", ObjectType::building }, // "Hotel"
        { "BLDALP11", ObjectType::building }, // "House"
        { "BLDALP4 ", ObjectType::building }, // "House"
        { "BLDALP5 ", ObjectType::building }, // "House"
        { "BLDALP6 ", ObjectType::building }, // "House"
        { "BLDHOU12", ObjectType::building }, // "House"
        { "BLDHOU13", ObjectType::building }, // "House"
        { "BLDHOU15", ObjectType::building }, // "House"
        { "BLDHOU19", ObjectType::building }, // "House"
        { "BLDHOU21", ObjectType::building }, // "House"
        { "BLDHOU22", ObjectType::building }, // "House"
        { "BLDHOU24", ObjectType::building }, // "House"
        { "BLDHOU25", ObjectType::building }, // "House"
        { "BLDHOUS3", ObjectType::building }, // "House"
        { "BLDHOU23", ObjectType::building }, // "House"
        { "BLDLIGHT", ObjectType::building }, // "Lighthouse"
        { "BLDCTY13", ObjectType::building }, // "Office Block"
        { "BLDCTY19", ObjectType::building }, // "Office Block"
        { "BLDCTY2 ", ObjectType::building }, // "Office Block"
        { "BLDCTY28", ObjectType::building }, // "Office Block"
        { "BLDCTY29", ObjectType::building }, // "Office Block"
        { "BLDCTY3 ", ObjectType::building }, // "Office Block"
        { "BLDCTY4 ", ObjectType::building }, // "Office Block"
        { "BLDCTY5 ", ObjectType::building }, // "Office Block"
        { "BLDCTY15", ObjectType::building }, // "Office Building"
        { "BLDCTY12", ObjectType::building }, // "Office Tower"
        { "BLDCTY1 ", ObjectType::building }, // "Offices"
        { "BLDCTY10", ObjectType::building }, // "Offices"
        { "BLDCTY11", ObjectType::building }, // "Offices"
        { "BLDCTY14", ObjectType::building }, // "Offices"
        { "BLDCTY7 ", ObjectType::building }, // "Offices"
        { "BLDHOU11", ObjectType::building }, // "Semi-Detached Houses"
        { "BLDALP10", ObjectType::building }, // "Shops"
        { "BLDSHOP1", ObjectType::building }, // "Shops"
        { "BLDCTY25", ObjectType::building }, // "Shops and Apartments"
        { "BLDCTY26", ObjectType::building }, // "Shops and Apartments"
        { "BLDCTY27", ObjectType::building }, // "Shops and Apartments"
        { "BLDCTY6 ", ObjectType::building }, // "Shops and Offices"
        { "BLDCTY8 ", ObjectType::building }, // "Shops and Offices"
        { "BLDCTY9 ", ObjectType::building }, // "Shops and Offices"
        { "BLDHOU16", ObjectType::building }, // "Shops and Offices"
        { "BLDCTY16", ObjectType::building }, // "Shops and Offices"
        { "BLDCTY22", ObjectType::building }, // "Tenement Building"
        { "BLDCTY23", ObjectType::building }, // "Tenement Building"
        { "BLDCTY24", ObjectType::building }, // "Tenement Building"
        { "BLDHOU17", ObjectType::building }, // "Terraced Houses"
        { "BLDHOUS2", ObjectType::building }, // "Terraced Houses"
        { "BLDOFF1 ", ObjectType::building }, // "Tower Block Flats"
        { "BLDPARK1", ObjectType::building }, // "Town Square"
        { "BLDALP7 ", ObjectType::building }, // "Townhouse"
        { "BLDALP9 ", ObjectType::building }, // "Townhouse"
        { "BLDTRANS", ObjectType::building }, // "Transmitter"

        // Type 29 (scaffolding)
        { "SCAFDEF ", ObjectType::scaffolding }, // "Scaffolding"

        // Type 30 (industry)
        { "BREWERY ", ObjectType::industry }, // "Brewery"
        { "CHEMWORK", ObjectType::industry }, // "Chemical Works"
        { "COALMINE", ObjectType::industry }, // "Coal Mines"
        { "COALPS  ", ObjectType::industry }, // "Coal-Fired Power Station"
        { "FACTORY ", ObjectType::industry }, // "Factory"
        { "WINDMILL", ObjectType::industry }, // "Flour Mill"
        { "FOODPROC", ObjectType::industry }, // "Food Processing Plant"
        { "OREMINE ", ObjectType::industry }, // "Iron Ore Mines"
        { "STOCKFRM", ObjectType::industry }, // "Livestock Farm"
        { "FOREST  ", ObjectType::industry }, // "Managed Forest"
        { "OILREFIN", ObjectType::industry }, // "Oil Refinery"
        { "OILRIG  ", ObjectType::industry }, // "Oil Rig"
        { "OILWELL ", ObjectType::industry }, // "Oil Wells"
        { "PAPERMIL", ObjectType::industry }, // "Paper Mill"
        { "PRINTWRK", ObjectType::industry }, // "Printing Works"
        { "SAWMILL ", ObjectType::industry }, // "Sawmill"
        { "SKICENT ", ObjectType::industry }, // "Ski Centre"
        { "STEELMIL", ObjectType::industry }, // "Steel Mill"
        { "VINEYARD", ObjectType::industry }, // "Vineyard"
        { "FARM    ", ObjectType::industry }, // "Wheat Farm"
        { "FARMUS  ", ObjectType::industry }, // "Wheat Farm"
        { "WINERY  ", ObjectType::industry }, // "Winery"

        // Type 31 (region)
        { "REGALP  ", ObjectType::region }, // "Alpine Mountains"
        { "REGUK   ", ObjectType::region }, // "Great Britain"
        { "REGUS   ", ObjectType::region }, // "North America"

        // Type 32 (competitor)
        { "COMP9   ", ObjectType::competitor }, // "Agnes Armchair"
        { "COMP5   ", ObjectType::competitor }, // "Alfred Ashdown"
        { "COMP22  ", ObjectType::competitor }, // "Basil Boombox"
        { "COMP28  ", ObjectType::competitor }, // "Bo Buzzball"
        { "COMP23  ", ObjectType::competitor }, // "Cecil Cityscape"
        { "COMP10  ", ObjectType::competitor }, // "Charles Chilblain"
        { "COMP6   ", ObjectType::competitor }, // "Corina Cross"
        { "COMP27  ", ObjectType::competitor }, // "Daisy Dastardly"
        { "COMP7   ", ObjectType::competitor }, // "Dave Doorknob"
        { "COMP20  ", ObjectType::competitor }, // "Dorothy Dumblebum"
        { "COMP21  ", ObjectType::competitor }, // "Evelyn Eggburt"
        { "COMP12  ", ObjectType::competitor }, // "Foo Fandango"
        { "COMP33  ", ObjectType::competitor }, // "Freddy Fiddlestick"
        { "COMP24  ", ObjectType::competitor }, // "Gary Gangle"
        { "COMP4   ", ObjectType::competitor }, // "Guiseppe Gluck"
        { "COMP13  ", ObjectType::competitor }, // "Harriet Hatstand"
        { "COMP18  ", ObjectType::competitor }, // "Isaac Imperial"
        { "COMP8   ", ObjectType::competitor }, // "Jeremy Jewelfish"
        { "COMP2   ", ObjectType::competitor }, // "Jillie Jamjar"
        { "COMP14  ", ObjectType::competitor }, // "Kathy Kilowatt"
        { "COMP15  ", ObjectType::competitor }, // "Lizzy Leopard"
        { "COMP30  ", ObjectType::competitor }, // "Maggie Munchkins"
        { "COMP16  ", ObjectType::competitor }, // "Marmaduke Muddleshop"
        { "COMP26  ", ObjectType::competitor }, // "Mick Motormouth"
        { "COMP29  ", ObjectType::competitor }, // "Mr Big"
        { "COMP34  ", ObjectType::competitor }, // "Naomi Nevermore"
        { "COMP35  ", ObjectType::competitor }, // "Oliver Organic"
        { "COMP32  ", ObjectType::competitor }, // "Pete Pennyweight"
        { "COMP17  ", ObjectType::competitor }, // "Reginald Rottenfish"
        { "COMP38  ", ObjectType::competitor }, // "Ricky Ripoff"
        { "COMP1   ", ObjectType::competitor }, // "Ronnie Riddlesworth"
        { "COMP3   ", ObjectType::competitor }, // "Rosie Redbone"
        { "COMP36  ", ObjectType::competitor }, // "Sue Shaker"
        { "COMP31  ", ObjectType::competitor }, // "Theodore Thin"
        { "COMP25  ", ObjectType::competitor }, // "Theresa Tops"
        { "COMP37  ", ObjectType::competitor }, // "Tony Terrific"
        { "COMP11  ", ObjectType::competitor }, // "Walter Wellington"
        { "COMP19  ", ObjectType::competitor }, // "Wodger Whamjet"

        // Type 33 (scenarioText)
        { "STEX043 ", ObjectType::scenarioText }, // "Aerophobia"
        { "STEX024 ", ObjectType::scenarioText }, // "Bottleneck Blues"
        { "STEX038 ", ObjectType::scenarioText }, // "Boulder Breakers"
        { "STEX040 ", ObjectType::scenarioText }, // "Clifftop Climb"
        { "STEX021 ", ObjectType::scenarioText }, // "Cyclade Capers"
        { "STEX025 ", ObjectType::scenarioText }, // "Desert Delirium"
        { "STEX022 ", ObjectType::scenarioText }, // "Dodecan Diaries"
        { "STEX036 ", ObjectType::scenarioText }, // "Feed Flintrock"
        { "STEX003 ", ObjectType::scenarioText }, // "Great Britain & Ireland - 100 Year Challenge"
        { "STEX000 ", ObjectType::scenarioText }, // "Great Britain & Ireland 1900"
        { "STEX001 ", ObjectType::scenarioText }, // "Great Britain & Ireland 1930"
        { "STEX002 ", ObjectType::scenarioText }, // "Great Britain & Ireland 1955"
        { "STEX034 ", ObjectType::scenarioText }, // "Keystone Keys"
        { "STEX030 ", ObjectType::scenarioText }, // "Lost Worlds"
        { "STEX027 ", ObjectType::scenarioText }, // "Mixing Muscle"
        { "STEX023 ", ObjectType::scenarioText }, // "Mountain Mayhem"
        { "STEX007 ", ObjectType::scenarioText }, // "North America (East) - 100 Year Challenge"
        { "STEX004 ", ObjectType::scenarioText }, // "North America (East) 1900"
        { "STEX005 ", ObjectType::scenarioText }, // "North America (East) 1950"
        { "STEX006 ", ObjectType::scenarioText }, // "North America (East) 1965"
        { "STEX011 ", ObjectType::scenarioText }, // "North America (Midwest) - 100 Year Challenge"
        { "STEX008 ", ObjectType::scenarioText }, // "North America (Midwest) 1920"
        { "STEX009 ", ObjectType::scenarioText }, // "North America (Midwest) 1945"
        { "STEX010 ", ObjectType::scenarioText }, // "North America (Midwest) 1970"
        { "STEX015 ", ObjectType::scenarioText }, // "North America (West) - 100 Year Challenge"
        { "STEX012 ", ObjectType::scenarioText }, // "North America (West) 1910"
        { "STEX013 ", ObjectType::scenarioText }, // "North America (West) 1955"
        { "STEX014 ", ObjectType::scenarioText }, // "North America (West) 1980"
        { "STEX031 ", ObjectType::scenarioText }, // "Oil Oasis"
        { "STEX041 ", ObjectType::scenarioText }, // "Pothole Peril"
        { "STEX020 ", ObjectType::scenarioText }, // "Race to Read"
        { "STEX042 ", ObjectType::scenarioText }, // "Rails Against Roads"
        { "STEX037 ", ObjectType::scenarioText }, // "Sandbox Settler"
        { "STEX028 ", ObjectType::scenarioText }, // "Santarinos"
        { "STEX032 ", ObjectType::scenarioText }, // "Smiley Isley"
        { "STEX039 ", ObjectType::scenarioText }, // "Snowy Heights"
        { "STEX033 ", ObjectType::scenarioText }, // "Stepping Stones"
        { "STEX019 ", ObjectType::scenarioText }, // "Swiss Alps - 100 Year Challenge"
        { "STEX016 ", ObjectType::scenarioText }, // "Swiss Alps 1905"
        { "STEX017 ", ObjectType::scenarioText }, // "Swiss Alps 1930"
        { "STEX018 ", ObjectType::scenarioText }, // "Swiss Alps 1960"
        { "STEX026 ", ObjectType::scenarioText }, // "Vache and Vineyards"
        { "STEX035 ", ObjectType::scenarioText }, // "Vapid Volcano"
        { "STEX044 ", ObjectType::scenarioText }, // "Weatherworld"
        { "STEX029 ", ObjectType::scenarioText }, // "Yew Island"
    };

    bool ObjectHeader::isVanilla() const
    {
        auto search = _vanillaObjects.find(std::make_tuple(getName(), getType()));
        return search != _vanillaObjects.end();
    }
}
