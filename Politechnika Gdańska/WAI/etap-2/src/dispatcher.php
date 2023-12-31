<?php

const REDIRECT_PREFIX = 'redirect:';

function dispatch($routing, $action_url){
    if(!array_key_exists($action_url, $routing)){
        http_response_code(404);
        exit;
    }
    $controller_name = $routing[$action_url];
    $model = [];
    $view = $controller_name($model);
    build_response($view, $model);
}

function build_response($view, $model){
    if(strpos($view, REDIRECT_PREFIX) === 0){
        $url = substr($view, strlen(REDIRECT_PREFIX));
        header("Location: " . $url);
        exit;
    }
    else {
        render($view, $model);
    }
}

function render($view, $model){
    global $routing;
    extract($model);
    include("views" . $view . ".phtml");
}

function is_ajax()
{
    return !empty($_SERVER['HTTP_X_REQUESTED_WITH']) &&
    strtolower($_SERVER['HTTP_X_REQUESTED_WITH']) == 'xmlhttprequest';
}