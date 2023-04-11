<script>
    function buttonClick() {
        alert("Button clicked");
    }
</script>

<h1>Hello World</h1>
<button class="button" on:click="{buttonClick}">Click!</button>

<style>
    .button {
        background-color: #4caf50; /* Green */
        border: none;
        color: white;
        padding: 15px 32px;
        text-align: center;
        text-decoration: none;
        display: inline-block;
        font-size: 16px;
    }
</style>
