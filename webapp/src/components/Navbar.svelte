<script>
    let showMenu = false;

    function toggleNavbar() {
      showMenu = !showMenu;
    }

    /**
     * @param {KeyboardEvent} evt
     */
    function toggleNavbarKeyPress(evt) {
      console.log(evt);
    }
</script>

<div class="bg-gray-800">
    <nav class="container px-6 py-8 mx-auto md:flex md:justify-between md:items-center">
        <div class="flex items-center justify-between">
            <a class="text-xl font-bold text-gray-100 md:text-2xl hover:text-blue-400" href="#">PCBCrew ESP32 Router</a>
            <!-- Mobile menu button -->
            <div on:click={toggleNavbar} on:keypress={toggleNavbarKeyPress} class="flex md:hidden">
                <button type="button" class="text-gray-100 hover:text-gray-400 focus:outline-none focus:text-gray-400">
                    <svg
                        xmlns="http://www.w3.org/2000/svg"
                        fill="none"
                        viewBox="0 0 24 24"
                        stroke-width="1.5"
                        stroke="currentColor"
                        class="w-6 h-6"
                        >
                        <path
                            stroke-linecap="round"
                            stroke-linejoin="round"
                            d="M3.75 6.75h16.5M3.75 12h16.5m-16.5 5.25h16.5"
                        />
                    </svg>
                </button>
            </div>
        </div>

        <!-- Mobile Menu open: "block", Menu closed: "hidden" -->
        <div class="flex-col mt-8 space-y-4 md:flex md:space-y-0 md:flex-row md:items-center md:space-x-10 md:mt-0 {showMenu ? 'flex' : 'hidden'}">
            <!-- <a class="text-gray-100 hover:text-blue-400" href="#">Home</a>
            <a class="text-gray-100 hover:text-blue-400" href="#">Logs</a>
            <a class="text-gray-100 hover:text-blue-400" href="#">Settings</a> -->
            <div class="space-y-2">
                <a href="https://pcbcrew.com" class="py-3 px-4 text-center border text-gray-800 bg-white hover:text-indigo-600 rounded-md block lg:inline lg:border-0">
                    Visit Website
                </a>
                <a href="https://linkedin.com/company/pcbcrew" class="py-3 px-4 text-center text-white bg-indigo-600 hover:bg-indigo-700 rounded-md shadow block lg:inline">
                    Linkedin
                </a>
            </div>
        </div>
    </nav>
</div>
