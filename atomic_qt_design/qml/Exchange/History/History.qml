import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

import "../../Components"
import "../../Constants"
import ".."

Item {
    id: exchange_history

    function inCurrentPage() {
        return  exchange.inCurrentPage() &&
                exchange.current_page === General.idx_exchange_history
    }

    function reset() {
    }

    function onOpened() {
        console.log("is_history false")
        API.get().orders_mdl.orders_proxy_mdl.is_history = true
        API.get().refresh_orders_and_swaps()
    }

    property string recover_funds_result: '{}'

    function onRecoverFunds(order_id) {
        const result = API.get().recover_fund(order_id)
        console.log(result)
        recover_funds_result = result
        recover_funds_modal.open()
    }

    ColumnLayout {
        anchors.horizontalCenter: parent.horizontalCenter

        width: parent.width
        height: parent.height
        spacing: 15

        SwapList {
            title: API.get().empty_string + (qsTr("Recent Swaps"))
            items: API.get().orders_mdl.orders_proxy_mdl
        }
    }

    OrderModal {
        id: order_modal
    }

    LogModal {
        id: recover_funds_modal

        title: API.get().empty_string + (qsTr("Recover Funds Result"))
        field.text: General.prettifyJSON(recover_funds_result)

        onClosed: recover_funds_result = "{}"
    }
}










/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
